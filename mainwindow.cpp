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



    Factory *factory = new Factory(ui->gameScreen);

    Worker *worker1 = new Worker("Cathal", skills::SEAMSTRESS);

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
