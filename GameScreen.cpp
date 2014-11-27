#include "GameScreen.h"
#include "ui_GameScreen.h"
GameScreen::GameScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameScreen)
{
    ui->setupUi(this);
    initWSButtons();
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

void GameScreen::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() + 1);
}


void GameScreen::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() - 1);
}

void GameScreen::initWSButtons()
{
    wsButtons = new QButtonGroup(this);
    wsButtons->addButton(ui->ws_1, 0);
    wsButtons->addButton(ui->ws_2, 1);
    wsButtons->addButton(ui->ws_3, 2);
    wsButtons->addButton(ui->ws_4, 3);
    wsButtons->addButton(ui->ws_5, 4);
    wsButtons->addButton(ui->ws_6, 5);
    wsButtons->addButton(ui->ws_7, 6);
    wsButtons->addButton(ui->ws_8, 7);
    wsButtons->addButton(ui->ws_9, 8);
    wsButtons->addButton(ui->ws_10, 9);
    wsButtons->addButton(ui->ws_11, 10);
    wsButtons->addButton(ui->ws_12, 11);
    wsButtons->addButton(ui->ws_13, 12);
    wsButtons->addButton(ui->ws_14, 13);
    wsButtons->addButton(ui->ws_15, 14);
    connect(wsButtons, SIGNAL(buttonClicked(int)),
            this, SLOT( WSView(int)));
}

void GameScreen::updateWSView(int num)
{
    this->ui->ws_label->setText(QString::fromStdString("Workstation " + to_string(num + 1)));
}

void GameScreen::updateTimer()
{

}

void GameScreen::setStations(vector<WorkStation*>  &stations)
{

    for(auto &station : stations)
    {
        cout << station->getDailyCount() << endl;
    }

}
