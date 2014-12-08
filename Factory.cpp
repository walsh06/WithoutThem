#include "Factory.h"
#include "iostream"
#include "GenerateWorker.h"
#include "EventSystem.h"
#include "Popup.h"


DatabaseManipulator Factory::db;
Factory::Factory(GameScreen* gameScreen)
{

    this->money = 1000.00;
    this->factoryLevel = 1;
    this->factoryUpgradeCost = 200;

    this->timer = new QTimer(this);


    connect(timer, SIGNAL(timeout()), this, SLOT(endDay()));
    eventSystem = new EventSystem();
    dayCount = 0;
    srand(time(0));
    this->gameScreen = gameScreen;
    this->gameScreen->setStations(stations);
    connect(gameScreen, SIGNAL(updateWage(double)), this, SLOT(setWage(double)));
    connect(gameScreen, SIGNAL(hireEmps()), this, SLOT(hireNewEmps()));
    connect(gameScreen, SIGNAL(checkExistingWorkerDetails(const QString&)), this, SLOT(checkWorkerDetails(const QString&)));
    connect(gameScreen, SIGNAL(fireWorker(const QString&)), this, SLOT(firingWorker(const QString&)));
    connect(gameScreen, SIGNAL(rehireOldEmps()), this, SLOT(hiringOldEmps()));
    connect(gameScreen, SIGNAL(factoryUpgrade()), this, SLOT(upgradeFactory()));
    //TEMP
    this->gameScreen->updateProductList(Factory::db.getProductNames(factoryLevel));
    gameScreen->setUpgradeCost(factoryUpgradeCost);
}

void Factory::startDay()
{
    dayCount++;
    if(dayCount > 5)
    {
        eventSystem->update(this);
    }
    gameScreen->updateFactory(dayCount, money, workers.size());
    gameScreen->updateWorkers(workers);


    for(auto &station : stations)
    {
        station->start();
    }

    timer->start(6000);    void upgradeFactory();

}

void Factory::endDay()
{
    for(auto &station : stations)
    {
        station->stop();
    }

    money += calcNetIncome();


   //"TEMP - Testing - restart day - should be done on button click or something" << endl;
    timer->stop();
    gameScreen->endDayPopup(calcWages(), calcGrossIncome(), money);
    // Possibly move to startDay()
    for(auto &worker : workers)
    {
        worker->setWorking(true);
    }

    startDay();
}

double Factory::getMoney()
{
    return money;
}

void Factory::setMoney(double money)
{
    this->money = money;
}

double Factory::calcGrossIncome()
{
    double dailyIncome = 0.00;

    for(auto &station : stations)
    {
        dailyIncome += (station->getProduct()->getValue() * station->getDailyCount());
    }

    return dailyIncome;
}

double Factory::calcWages()
{
    double dailyWages = 0.00;
    for(auto &worker : workers)
    {
        dailyWages += worker->getWagePerDay();
    }

    return dailyWages;
}

double Factory::calcNetIncome()
{
    double net = calcGrossIncome() - calcWages();

    return net;
}

void Factory::addStation(WorkStation* station)
{
    connect(station, SIGNAL(updateWS()), gameScreen, SLOT(updateWSView()));
    stations.push_back(station);


    this->gameScreen->setStations(stations);
}

void Factory::removeStation(WorkStation* station)
{
    //Moves station to the end, erases last station
    stations.erase(std::remove(stations.begin(), stations.end(), station), stations.end());

    this->gameScreen->setStations(stations);
}

void Factory::addWorker(Worker* worker)
{
    workers.push_back(worker);
}

void Factory::removeWorker(Worker* worker)
{
    workers.erase(std::remove(workers.begin(), workers.end(), worker), workers.end());
}

int Factory::getDayCount()
{
    return dayCount;
}

void Factory::changeWorkerMoral(int moral)
{
    if(workers.size())
    {
        int randWorker = rand() % workers.size();

        workers[randWorker]->setMoral(moral);
    }
}

void Factory::stopWorkstation()
{
    if(stations.size())
    {
        int randStation = rand() % stations.size();

        stations[randStation]->setWorking(false);
    }
}

void Factory::killWorker()
{
    if(workers.size())
    {
    int randWorker = rand() % workers.size();
    workers.erase(std::remove(workers.begin(), workers.end(),  workers[randWorker]), workers.end());
    }

}

void Factory::setWage(double wage)
{
    for(auto &worker : workers)
    {
        worker->setWagePerDay(wage);
    }
}

void Factory::hireNewEmps()
{
    int i, num = (rand() % 3) + 2;
    vector<Worker* > nw;
    for(vector<Worker*>::size_type i = 0; i < num; i++){
        nw.push_back(generateW::generateWorker());
    }

    popup = new Popup();

    connect(popup,SIGNAL(addNewWorker(Worker*)),this, SLOT(addNewHire(Worker*)));
    popup->addWorkers(nw, num);
    popup->exec();
}

void Factory::addingOldWorker(const QString& s)
{
    int i = 0;
    for(i = 0; i < this->firedEmps.size(); i ++){
        if(s.toStdString() == firedEmps.at(i)->getName()){
            break;
        }
    }
    Worker* w = firedEmps.at(i);
    addNewHire(w);

}

void Factory::addNewHire(Worker* w)
{
    addWorker(w);
    gameScreen->updateWorkers(workers);
    gameScreen->displayWorkerDetails(w);

}

void Factory::hiringOldEmps()
{
    rehireWindow = new ReHireWindow();
    connect(rehireWindow,SIGNAL(rehiring(const QString&)),this, SLOT(addingOldWorker(const QString&)));
    rehireWindow->updateWorkers(firedEmps);
    connect(rehireWindow,SIGNAL(checkFiredWorkerDetails(const QString&)), this, SLOT(findFiredWorker(const QString&)));

    rehireWindow->exec();
}

void Factory::findFiredWorker(const QString& s)
{
    int i = 0;
    for(i = 0; i < this->firedEmps.size(); i ++){
        if(s.toStdString() == firedEmps.at(i)->getName()){
            break;
        }
    }
    Worker* w = firedEmps.at(i);
    rehireWindow->updateDetailsView(w);
}


void Factory::checkWorkerDetails(const QString& s)
{
    int i = 0;
    for(i = 0; i < this->workers.size(); i ++){
        if(s.toStdString() == workers.at(i)->getName()){
            break;
        }
    }
    Worker* w = workers.at(i);
    gameScreen->displayWorkerDetails(w);

}

void Factory::firingWorker(const QString& s)
{
    int i = 0;
    for(i = 0; i < this->workers.size(); i ++){
        if(s.toStdString() == workers.at(i)->getName()){
            break;
        }
    }
    firedEmps.push_back(workers.at(i));
    removeWorker(workers.at(i));
    gameScreen->updateWorkers(workers);
}

GameScreen* Factory::getGameScreen()
{
    return gameScreen;
}

void Factory::upgradeFactory()
{
    if(money > factoryUpgradeCost)
    {
        factoryLevel++;
        money -= factoryUpgradeCost;
        factoryUpgradeCost = factoryUpgradeCost * 2;
        gameScreen->displayUpgrade(true, factoryLevel, money, factoryUpgradeCost);
        this->gameScreen->updateProductList(Factory::db.getProductNames(factoryLevel));
    }
    else
    {
        gameScreen->displayUpgrade(false, factoryLevel, money, factoryUpgradeCost);
    }
}
