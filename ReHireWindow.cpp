#include "ReHireWindow.h"
#include "ui_ReHireWindow.h"
#include <iostream>

/**Creates a re-hire pop up window*/
ReHireWindow::ReHireWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReHireWindow)
{
    ui->setupUi(this);
}

/**Destructor*/
ReHireWindow::~ReHireWindow()
{
    delete ui;
}

/**Hire button is clicked the selected worker is re hired*/
void ReHireWindow::on_rehireButton_clicked()
{
    ui->compareWindow->clear();
    ui->employeesList->clear();
    for(int i = 0; i < ui->firedList->count(); i++){
        if(ui->firedList->item(i)->isSelected()){
            const QString& s = ui->firedList->currentItem()->text();
            emit rehiring(s);
            break;
        }
    }
}

/**Compare button is clicked the selected workers are compared*/
void ReHireWindow::on_compareWorkers_clicked()
{
    QString s1, s2;
    ui->compareWindow->clear();
    for(int i = 0; i < ui->firedList->count(); i++){
        if(ui->firedList->item(i)->isSelected()){
            s1 = ui->firedList->currentItem()->text();
            break;
        }
    }
    for(int j = 0; j < ui->employeesList->count(); j++){
        if(ui->employeesList->item(j)->isSelected()){
            s2 = ui->employeesList->currentItem()->text();
            break;
        }
    }

    const QString& str1 = s1;
    const QString& str2 = s2;
    emit compareWorkers(str1, str2);
}

/**Details button is clicked the selected worker's details are shown*/
void ReHireWindow::on_workerDetailsButton_clicked()
{
    ui->compareWindow->clear();
    for(int i = 0; i < ui->firedList->count(); i++){
        if(ui->firedList->item(i)->isSelected()){
            const QString& s = ui->firedList->currentItem()->text();
            emit checkFiredWorkerDetails(s);
            break;
        }
    }
}

/**Takes a worker and updates the details window with the workers details*/
void ReHireWindow::updateDetailsView(Worker* w)
{
    ui->compareWindow->addItem(QString::fromStdString("Name: " + w->getName()));
    ui->compareWindow->addItem(QString::fromStdString("Age: "
                               + std::to_string(w->getBackground().getAge())));
    if(w->getBackground().hasHusband()){
        ui->compareWindow->addItem(QString::fromStdString("Spouse: true"));
    }else{
        ui->compareWindow->addItem(QString::fromStdString("Spouse: false"));
    }
    ui->compareWindow->addItem(QString::fromStdString("Daily Wage: "
                               + std::to_string(w->getWagePerDay())));
    ui->compareWindow->addItem(QString::fromStdString("Worker Moral: "
                               + std::to_string(w->getMoral())));
    ui->compareWindow->addItem(QString::fromStdString("Build skill: "
                               + std::to_string(w->getStats().getBuildingSkill())));
    ui->compareWindow->addItem(QString::fromStdString("Carpentry skill: "
                               + std::to_string(w->getStats().getCarpentrySkill())));
    ui->compareWindow->addItem(QString::fromStdString("Machine skill: "
                               + std::to_string(w->getStats().getMachinerySkill())));
    ui->compareWindow->addItem(QString::fromStdString("Farm skill: "
                               + std::to_string(w->getStats().getFarmingSkill())));
    ui->compareWindow->addItem(QString::fromStdString("Textile skill: "
                               + std::to_string(w->getStats().getTextileSkill())));
    ui->compareWindow->addItem(QString::fromStdString("Childern: "
                               + std::to_string(w->getBackground().getNumChildren())));
    ui->compareWindow->addItem(QString::fromStdString("Siblings: "
                               + std::to_string(w->getBackground().getNumSiblings())));
}

/**Adds a string to the compare window*/
void ReHireWindow::updateComparedWorkersWindow(QString s)
{
    ui->compareWindow->addItem(s);
}

/**Populates the fired window with a list of fired workers*/
void ReHireWindow::updateFiredWorkers(vector<Worker *> firedWorkers)
{
    while(ui->firedList->count()>0)
    {
      ui->firedList->takeItem(0);//handle the item if you don't
                              //have a pointer to it elsewhere
    }

    for(auto &worker: firedWorkers)
    {
        new QListWidgetItem(QString::fromStdString(worker->getName()), ui->firedList);
    }
}

/**Populates the employees window with the list of employees*/
void ReHireWindow::updateEmployees(map<string, Worker*> emps)
{
    while(ui->employeesList->count()>0)
    {
      ui->employeesList->takeItem(0);//handle the item if you don't
                              //have a pointer to it elsewhere
    }

    for(auto &worker: emps)
    {
        new QListWidgetItem(QString::fromStdString(worker.second->getName()), ui->employeesList);
    }
}
