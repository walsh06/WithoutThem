#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SkillTypeEnums.h"
#include <QTimer>

#include "WorkStation.h"
#include "Worker.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);


    //Product *product = new Product("Uniform", skills::BUILDER, 10, 1000,"Cotton", 15.00);
    Factory *factory = new Factory(ui->gameScreen);

    Worker *worker1 = new Worker("Cathal", skills::SEAMSTRESS);
    Worker *worker2 = new Worker("Liam", skills::CARPENTER);
    Worker *worker3 = new Worker("Killian", skills::FARMER);

    WorkStation *ws = new WorkStation("Uniform");

    ws->assignWorker(worker1);


    factory->addStation(ws);

    factory->startDay();
}

MainWindow::~MainWindow()
{
    delete ui;
}
