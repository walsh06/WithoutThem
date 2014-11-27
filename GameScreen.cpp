#include "GameScreen.h"
#include "ui_GameScreen.h"

GameScreen::GameScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameScreen)
{
    ui->setupUi(this);
}

GameScreen::~GameScreen()
{
    delete ui;
}

void GameScreen::updateFactory(int dayCount, double money, int workerCount)
{
    ui->days->setText(QString::number(dayCount));
    ui->money->setText(QString::number(money));
    ui->workerCount->setText((QString::number(workerCount)));
}

void GameScreen::on_setWageBox_valueChanged(double arg1)
{
    emit updateWage(arg1);
}

void GameScreen::updateWorkers(std::vector<Worker*> workers)
{
    while(ui->workerList->count()>0)
    {
      ui->workerList->takeItem(0);//handle the item if you don't
                              //have a pointer to it elsewhere
    }
    for(auto &worker: workers)
    {
        new QListWidgetItem(QString::fromStdString(worker->getName()), ui->workerList);
    }
}
