#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SkillTypeEnums.h"
#include <QTimer>

#include "WorkStation.h"
#include "Worker.h"
#include "GenerateWorker.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);



    Factory *factory = new Factory(ui->gameScreen);

    Worker *worker1 = new Worker("Cathal", skills::SEAMSTRESS);
    Worker *worker2 = new Worker("Liam", skills::CARPENTER);
    Worker *worker3 = new Worker("Killian", skills::FARMER);
    GenerateWorker* gw = new GenerateWorker();
    gw->generateWorker();
    Worker *worker4 = gw->getWorker();
    gw->generateWorker();
    Worker *worker5 = gw->getWorker();

    worker1->printWorker();
    worker2->printWorker();
    worker3->printWorker();
    worker4->printWorker();
    worker5->printWorker();

    WorkStation *ws = new WorkStation("Uniform");

    ws->assignWorker(worker1);


    factory->addWorker(worker1);

    factory->addStation(ws);

    factory->startDay();
}

MainWindow::~MainWindow()
{
    delete ui;
}
