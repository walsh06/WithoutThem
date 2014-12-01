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

    Worker *worker1 = new Worker("Cathal");
    Worker *worker2 = new Worker("Liam");
    Worker *worker3 = new Worker("Killian");

    std::cout<< worker1->printWorker() << std::endl;
    std::cout<< worker2->printWorker() << std::endl;
    std::cout<< worker3->printWorker() << std::endl;

    WorkStation *ws = new WorkStation("Uniform");

    ws->assignWorker(worker1);


    factory->addWorker(worker1);
    factory->addWorker(worker2);
    factory->addWorker(worker3);

    factory->addStation(ws);

    factory->startDay();
}

MainWindow::~MainWindow()
{
    delete ui;
}
