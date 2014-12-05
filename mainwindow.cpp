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
    ui->menuStack->setCurrentIndex(1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    startGame();
    ui->menuStack->setCurrentIndex(0);
}

void MainWindow::startGame()
{
    Factory *factory = new Factory(ui->gameScreen);

    Worker *worker1 = new Worker("Cathal", skills::SEAMSTRESS);

    WorkStation *ws = new WorkStation("Helmet");

    ws->assignWorker(worker1);


    factory->addWorker(worker1);

    factory->addStation(ws);

    factory->startDay();
}
