#include "Popup.h"
#include "ui_popup.h"
#include "QListView"
#include "QListWidgetItem"
#include "iostream"

Popup::Popup(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Popup)
{    
    ui->setupUi(this);

    this->listWidgets.push_back(ui->listWidget);
    this->listWidgets.push_back(ui->listWidget_2);
    this->listWidgets.push_back(ui->listWidget_3);
    this->listWidgets.push_back(ui->listWidget_4);
    ui->listWidget_3->hide();
    ui->listWidget_4->hide();

    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
}

Popup::~Popup()
{
    delete ui;
}

void Popup::addWorkers(vector<Worker*> nw, int num)
{
    this->nw = nw;
    if(num > 2){
        activateSlots(num);
    }
    /*Worker* w1 = new Worker("Killian");
    Worker* w2 = new Worker("Kan");
    Worker* w3 = new Worker("Ian");
    Worker* w4 = new Worker("Kill");

    std::vector<int>::size_type i = 0;
    for(auto &w: nw){
        populateCells(w, listWidgets[i]);
        i++;

    }
    for(int i = 0; i < num; i++)
    {
        populateCells(this->nw[i], listWidgets[i]);
    }*/


    QListWidgetItem* qlwi_1 = new QListWidgetItem(QString::fromStdString(nw[0]->printWorker()), ui->listWidget);
    QListWidgetItem* qlwi_2 = new QListWidgetItem(QString::fromStdString(nw[1]->printWorker()), ui->listWidget_2);
    if(num == 3){
        QListWidgetItem* qlwi_3 = new QListWidgetItem(QString::fromStdString(nw[2]->printWorker()), ui->listWidget_3);
    }else if (num == 4){
        QListWidgetItem* qlwi_3 = new QListWidgetItem(QString::fromStdString(nw[2]->printWorker()), ui->listWidget_3);
        QListWidgetItem* qlwi_4 = new QListWidgetItem(QString::fromStdString(nw[3]->printWorker()), ui->listWidget_4);
    }
}

void Popup::activateSlots(int num)
{
    ui->listWidget_3->show();
    ui->pushButton_3->show();
    if(num == 4){
        ui->listWidget_4->show();
        ui->pushButton_4->show();
    }
}

void Popup::populateCells(Worker* w, QListWidget* lWidget)
{
    new QListWidgetItem(QString::fromStdString(w->printWorker()), lWidget);
}


void Popup::on_pushButton_clicked()
{
    this->close();
    emit addNewWorker(nw[0]);
}

void Popup::on_pushButton_2_clicked()
{
    this->close();
    emit addNewWorker(nw[1]);
}

void Popup::on_pushButton_3_clicked()
{
    this->close();
    emit addNewWorker(nw[2]);
}

void Popup::on_pushButton_4_clicked()
{
    this->close();
    emit addNewWorker(nw[3]);
}
