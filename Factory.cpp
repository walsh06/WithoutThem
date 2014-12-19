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
    connect(gameScreen, SIGNAL(productUpgrade(string)), this, SLOT(upgradeProduct(string)));
    //TEMP
    this->gameScreen->updateProductList(Factory::db.getProductNames(factoryLevel));
    this->gameScreen->updateUpdateProductList(Factory::db.getProductNames(factoryLevel));
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

    timer->start(6000);
    void upgradeFactory();
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
    for(auto &value : workers)
    {
        value.second->setWorking(true);
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
    for(auto &value : workers)
    {
        dailyWages += value.second->getWagePerDay();
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
    workers[worker->getName()]=worker;
}

void Factory::removeWorker(Worker* worker)
{
    for(auto &station: stations)
    {
        station->removeWorker(worker);
    }

    workers.erase(worker->getName());
}

void Factory::removeWorker(string workerName)
{
    for(auto &station: stations)
    {
        station->removeWorker(workerName);
    }
    workers.erase(workerName);
}

int Factory::getDayCount()
{
    return dayCount;
}

void Factory::changeWorkerMoral(int moral)
{
    if(workers.size())
    {

        auto it = workers.begin();
        std::advance(it, rand() % workers.size());
        Worker* randomWorker = it->second;

        randomWorker->setMoral(moral);
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
    if(workers.size() > 0)
    {

        auto it = workers.begin();
        std::advance(it, rand() % workers.size());
        string randomWorker = it->first;

        removeWorker(randomWorker);
    }

}

void Factory::setWage(double wage)
{
    for(auto &worker : workers)
    {
        worker.second->setWagePerDay(wage);
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
    int i = findWorkerByName(firedEmps, s);
    Worker* w = firedEmps.at(i);
    firedEmps.erase(std::remove(firedEmps.begin(), firedEmps.end(), w), firedEmps.end());
    rehireWindow->updateFiredWorkers(firedEmps);
    addNewHire(w);
    rehireWindow->updateEmployees(workers);

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
    connect(rehireWindow,SIGNAL(checkFiredWorkerDetails(const QString&)), this, SLOT(findFiredWorker(const QString&)));
    connect(rehireWindow,SIGNAL(compareWorkers(const QString&, const QString&)), this, SLOT(comparingWorkers(const QString&, const QString&)));
    rehireWindow->updateFiredWorkers(firedEmps);
    rehireWindow->updateEmployees(workers);
    rehireWindow->exec();
}

void Factory::comparingWorkers(const QString& s1, const QString& s2)
{
    int i = findWorkerByName(firedEmps, s1);
    //int j = findWorkerByName(workers, s2);
    Worker* w1 = firedEmps.at(i);
    Worker* w2 = workers[s2.toStdString()];
    string compared = w1->compareWorkers(w2);
    rehireWindow->updateComparedWorkersWindow(QString::fromStdString(compared));
}


void Factory::findFiredWorker(const QString& s)
{
    int i = findWorkerByName(firedEmps, s);
    Worker* w = firedEmps.at(i);
    rehireWindow->updateDetailsView(w);
}


void Factory::checkWorkerDetails(const QString& s)
{
    //int i = findWorkerByName(workers, s);
    Worker* w = workers[s.toStdString()];
    gameScreen->displayWorkerDetails(w);

}

void Factory::firingWorker(const QString& s)
{
    //int i = findWorkerByName(workers,s);

    workers[s.toStdString()]->setMoral(-3);
    firedEmps.push_back(workers[s.toStdString()]);
    removeWorker(s.toStdString());
    gameScreen->updateWorkers(workers);
}

int Factory::findWorkerByName(vector<Worker*> list, const QString& s)
{
    int i = 0;
    for(i = 0; i < list.size(); i ++){
        if(s.toStdString() == list.at(i)->getName()){
            break;
        }
    }
    return i;
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
        this->gameScreen->updateUpdateProductList(Factory::db.getProductNames(factoryLevel));
    }
    else
    {
        gameScreen->displayUpgrade(false, factoryLevel, money, factoryUpgradeCost);
    }
}

void Factory::upgradeProduct(string name){
    if(name != "Choose Product"){
        int cost = Factory::db.getProductCost(name);
        std::cout<< name;
        std::cout<< " costs ";
        std::cout<< cost << std::endl;
        this->money = money - (double)cost;
        Factory::db.upgradeProduct(name);
    }
}
