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

void GameScreen::updateProductList(vector<string> list)
{
    for(auto &s : list)
    {
        ui->productList->addItem(QString::fromStdString(s));
    }
    ui->productList->setCurrentIndex(-1);
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
            this, SLOT( updateCurrentWS(int)));
}

void GameScreen::updateCurrentWS(int num)
{
    currentWS = num;
    updateWSView();
}

void GameScreen::updateWSView()
{
    this->ui->ws_label->setText(QString::fromStdString("Workstation " + to_string(currentWS + 1)));
    if(currentWS < stations.size())
    {
        int numWorkers = stations[currentWS]->getNumWorkers() ;
        this->ui->stationWorkerCount->setText(QString::fromStdString("No. of Workers: " +
                                                              to_string(numWorkers)));

        int daily = stations[currentWS]->getDailyCount();
        this->ui->prodcount->setText(QString::fromStdString("Products Generated Today: " +
                                                              to_string(daily)));
    } else {
        this->ui->stationWorkerCount->setText(QString::fromStdString("No. of Workers: N/A"));
        this->ui->prodcount->setText(QString::fromStdString("Products Generated Today: N/A"));
    }
}

void GameScreen::updateTimer()
{

}

void GameScreen::setStations(vector<WorkStation*>  &stations)
{
    this->stations = stations;
}

void GameScreen::eventPopup(string event)
{
    QMessageBox::information(
        this,
        tr("Event"),
        QString::fromStdString(event));
}

void GameScreen::endDayPopup(double wages, double gross, double money)
{
    this->wages = wages;
    this->gross = gross;
    this->money = money;
    this->income = gross - wages;

    ui->gross->setText(QString::number(gross));
    ui->wages->setText(QString::number(wages));
    ui->net->setText(QString::number(income));

    QMessageBox::information(
        this,
        tr("End of Day"),
        QString::fromStdString("Gross Income: ") + QString::number(gross) +
        QString::fromStdString("\n Wages: ") + QString::number(wages) +
        QString::fromStdString("\n-----------------") +
        QString::fromStdString("\n Net Income: ") + QString::number(income) +
        QString::fromStdString("\n Money: ") + QString::number(money)
                );
    /*QMessageBox box;
    box.setText(QString::fromStdString("Gross Income: ") + QString::number(gross) +
                QString::fromStdString("\n Wages: ") + QString::number(wages) +
                QString::fromStdString("\n-----------------") +
                QString::fromStdString("\n Net Income: ") + QString::number(income) +
                QString::fromStdString("\n Money: ") + QString::number(money));
    box.setWindowTitle("End Of Day");
    box.exec();*/
}
