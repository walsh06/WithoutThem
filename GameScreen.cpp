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
