#include "ReHireWindow.h"
#include "ui_ReHireWindow.h"
#include <iostream>

ReHireWindow::ReHireWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReHireWindow)
{
    ui->setupUi(this);
}

ReHireWindow::~ReHireWindow()
{
    delete ui;
}

void ReHireWindow::on_rehireButton_clicked()
{
    ui->compareWindow->clear();
    ui->employeesList->clear();
    for(int i = 0; i < ui->firedList->count(); i++){
        if(ui->firedList->item(i)->isSelected()){
            const QString& s = ui->firedList->currentItem()->text();
            std::cout<<"name = " + s.toStdString() << std::endl;
            emit rehiring(s);
            break;
        }
    }
}

void ReHireWindow::on_compareWorkers_clicked()
{

}

//Fix this and start the rest.
void ReHireWindow::on_workerDetailsButton_clicked()
{
    ui->compareWindow->clear();
    ui->employeesList->clear();
    for(int i = 0; i < ui->firedList->count(); i++){
        if(ui->employeesList->item(i)->isSelected()){
            const QString& s = ui->employeesList->currentItem()->text();
            emit checkFiredWorkerDetails(s);
            break;
        }
    }
}

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

void ReHireWindow::updateWorkers(vector<Worker *> firedWorkers)
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
