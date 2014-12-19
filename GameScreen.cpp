#include "GameScreen.h"
#include "ui_GameScreen.h"
#include "Factory.h"

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
    ui->productList->clear();
    ui->productList->addItem("Choose Product");
    for(auto &s : list)
    {
        ui->productList->addItem(QString::fromStdString(s));
    }
}

void GameScreen::updateUpdateProductList(vector<string> list)
{
    ui->productListUpdateBox->clear();
    ui->productListUpdateBox->addItem("Choose Product");
    for(auto &s : list)
    {
        ui->productListUpdateBox->addItem(QString::fromStdString(s));
    }
}


void GameScreen::on_setWageBox_valueChanged(double arg1)
{
    emit updateWage(arg1);
}

void GameScreen::updateWorkers(std::map<string, Worker*> workers)
{


    while(ui->workerList->count()>0)
    {
      ui->workerList->takeItem(0);//handle the item if you don't
                              //have a pointer to it elsewhere
    }


    ui->hireList->clear();
    ui->hireList->addItem("Choose Worker");
    for(auto &worker: workers)
    {
        new QListWidgetItem(QString::fromStdString(worker.second->getName()), ui->workerList);
        ui->hireList->addItem(QString::fromStdString(worker.second->getName()));
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

        string item = "Manufacturing : " + stations[currentWS]->getProduct()->getName();
        ui->manufactureLabel->setText(QString::fromStdString(item));

        updateTimer();


    } else {
        this->ui->stationWorkerCount->setText(QString::fromStdString("No. of Workers: N/A"));
        this->ui->prodcount->setText(QString::fromStdString("Products Generated Today: N/A"));
        ui->manufactureLabel->setText(QString::fromStdString("Manufacturing : N/A"));
    }
}

void GameScreen::updateTimer()
{

    QTime time(0,0,0);
    if(currentWS < stations.size())
    {
       time = QTime(stations[currentWS]->timer->remainingTime() / 60000,
                   stations[currentWS]->timer->remainingTime() / 1000,
                   0);
    }
        this->ui->timeEdit->setTime(time);



    QTimer::singleShot(100, this, SLOT(updateTimer()));
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

    //Breaks.
    //stations[currentWS]->setProduct(ui->productList->currentText().toStdString());

void GameScreen::on_manufactureButton_clicked()
{
    if(ui->productList->currentIndex() > 0)
        stations[currentWS]->setProduct(ui->productList->currentText().toStdString());
}

void GameScreen::on_hireButton_clicked()
{

}

void GameScreen::on_generateWorker_clicked()
{
    ui->workerDetails->clear();
    emit hireEmps();
}

void GameScreen::on_workerDetailsButton_clicked()
{
    ui->workerDetails->clear();
    for(int i = 0; i < ui->workerList->count(); i++){
        if(ui->workerList->item(i)->isSelected()){
            const QString& s = ui->workerList->currentItem()->text();
            emit checkExistingWorkerDetails(s);
            break;
        }
    }
}

void GameScreen::displayWorkerDetails(Worker* w)
{
    ui->workerDetails->addItem(QString::fromStdString("Name: " + w->getName()));
    ui->workerDetails->addItem(QString::fromStdString("Age: "
                               + std::to_string(w->getBackground().getAge())));
    if(w->getBackground().hasHusband()){
        ui->workerDetails->addItem(QString::fromStdString("Spouse: true"));
    }else{
        ui->workerDetails->addItem(QString::fromStdString("Spouse: false"));
    }
    ui->workerDetails->addItem(QString::fromStdString("Daily Wage: "
                               + std::to_string(w->getWagePerDay())));
    ui->workerDetails->addItem(QString::fromStdString("Worker Moral: "
                               + std::to_string(w->getMoral())));
    ui->workerDetails->addItem(QString::fromStdString("Build skill: "
                               + std::to_string(w->getStats().getBuildingSkill())));
    ui->workerDetails->addItem(QString::fromStdString("Carpentry skill: "
                               + std::to_string(w->getStats().getCarpentrySkill())));
    ui->workerDetails->addItem(QString::fromStdString("Machine skill: "
                               + std::to_string(w->getStats().getMachinerySkill())));
    ui->workerDetails->addItem(QString::fromStdString("Farm skill: "
                               + std::to_string(w->getStats().getFarmingSkill())));
    ui->workerDetails->addItem(QString::fromStdString("Textile skill: "
                               + std::to_string(w->getStats().getTextileSkill())));
    ui->workerDetails->addItem(QString::fromStdString("Childern: "
                               + std::to_string(w->getBackground().getNumChildren())));
    ui->workerDetails->addItem(QString::fromStdString("Siblings: "
                               + std::to_string(w->getBackground().getNumSiblings())));
}

void GameScreen::on_fireWorker_clicked()
{
    ui->workerDetails->clear();
    for(int i = 0; i < ui->workerList->count(); i++){
        if(ui->workerList->item(i)->isSelected()){
            const QString& s = ui->workerList->currentItem()->text();
            emit fireWorker(s);
            break;
        }
    }
}

void GameScreen::on_rehireWorkerButton_clicked()
{
    ui->workerDetails->clear();
    emit rehireOldEmps();
}


void GameScreen::displayUpgrade(bool success, int level, double money, double upgradeCost)
{
    if(success)
    {
        ui->money->setText(QString::number(money));
        ui->upgradeAmount->setText(QString::number(upgradeCost));
        QMessageBox::information(
        this,
        tr("Succesful Upgrade"),
        QString::fromStdString("Upgraded Factory to level ") + QString::number(level)
                );

    }
    else
    {
        QMessageBox::information(
            this,
            tr("Failed Upgrade"),
            QString::fromStdString("Failed to upgrade Factory to next level") +
            QString::fromStdString("\n Money: ") + QString::number(money) +
            QString::fromStdString("\n Required: ") + QString::number(upgradeCost));
    }
}

void GameScreen::setUpgradeCost(double cost)
{
    ui->upgradeAmount->setText(QString::number(cost));
}

void GameScreen::on_upgradeFactory_clicked()
{
    emit factoryUpgrade();
}

void GameScreen::on_updateProductsButton_clicked()
{
    string product = ui->productListUpdateBox->currentText().toStdString();
    emit productUpgrade(product);
    std::cout<< product << std::endl;
}
