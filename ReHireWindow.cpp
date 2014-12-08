#include "ReHireWindow.h"
#include "ui_ReHireWindow.h"

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
            //emit checkExistingWorkerDetails(s);
            break;
        }
    }
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
