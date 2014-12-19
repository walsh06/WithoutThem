#include "Factory.h"
#include "iostream"
#include "GenerateWorker.h"
#include "EventSystem.h"
#include "Popup.h"


/**The Database helper class*/
DatabaseManipulator Factory::db;

/**creates a new Factory object with a gameScreen pointer*/
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

<<<<<<< HEAD
    this->addFloor();
=======
    /**Connection various buttons to methods*/
>>>>>>> e694275795f2b88fd369ca2ea63cb7a2f89fc905
    connect(gameScreen, SIGNAL(updateWage(double)), this, SLOT(setWage(double)));
    connect(gameScreen, SIGNAL(hireEmps()), this, SLOT(hireNewEmps()));
    connect(gameScreen, SIGNAL(checkExistingWorkerDetails(const QString&)), this, SLOT(checkWorkerDetails(const QString&)));
    connect(gameScreen, SIGNAL(fireWorker(const QString&)), this, SLOT(firingWorker(const QString&)));
    connect(gameScreen, SIGNAL(rehireOldEmps()), this, SLOT(hiringOldEmps()));
    connect(gameScreen, SIGNAL(factoryUpgrade()), this, SLOT(upgradeFactory()));
<<<<<<< HEAD

    connect(gameScreen, SIGNAL(hireButton(int, string)), this, SLOT(addWorkerToStation(int, string)));
    //TEMP
=======
    connect(gameScreen, SIGNAL(productUpgrade(string)), this, SLOT(upgradeProduct(string)));

    /**Updating the gameScreen product lists*/
>>>>>>> e694275795f2b88fd369ca2ea63cb7a2f89fc905
    this->gameScreen->updateProductList(Factory::db.getProductNames(factoryLevel));
    this->gameScreen->updateUpdateProductList(Factory::db.getProductNames(factoryLevel));
    gameScreen->setUpgradeCost(factoryUpgradeCost);
}

/**Stats a day in the factory*/
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

<<<<<<< HEAD
    timer->start(60000);

=======
    /**length of the day*/
    timer->start(60000);
    void upgradeFactory();
>>>>>>> e694275795f2b88fd369ca2ea63cb7a2f89fc905
}

/**Starts the end of the day*/
void Factory::endDay()
{
    for(auto &station : stations)
    {
        station->stop();
    }

    money += calcNetIncome();


    timer->stop();
    gameScreen->endDayPopup(calcWages(), calcGrossIncome(), money);
    // Possibly move to startDay()
    for(auto &value : workers)
    {
        value.second->setWorking(true);
    }

    startDay();
}

/**Returns the money in the Factory*/
double Factory::getMoney()
{
    return money;
}

/**Set the amount of money in the factory*/
void Factory::setMoney(double money)
{
    this->money = money;
}

/**Calculate the Gross Income of the factory*/
double Factory::calcGrossIncome()
{
    double dailyIncome = 0.00;

    for(auto &station : stations)
    {
        dailyIncome += (station->getProduct()->getValue() * station->getDailyCount());
    }

    return dailyIncome;
}

/**Calculate the wages of all the employees*/
double Factory::calcWages()
{
    double dailyWages = 0.00;
    for(auto &value : workers)
    {
        dailyWages += value.second->getWagePerDay();
    }

    return dailyWages;
}

/**Calculate the Net income of the factory*/
double Factory::calcNetIncome()
{
    double net = calcGrossIncome() - calcWages();

    return net;
}

void Factory::addFloor()
{
    addStation(new WorkStation());
    addStation(new WorkStation());
    addStation(new WorkStation());
}

/**Add a new work station to the factory*/
void Factory::addStation(WorkStation* station)
{
    connect(station, SIGNAL(updateWS()), gameScreen, SLOT(updateWSView()));
    stations.push_back(station);


    this->gameScreen->setStations(stations);
}

/**Removes the last station in the list of work stations*/
void Factory::removeStation(WorkStation* station)
{
    //Moves station to the end, erases last station
    stations.erase(std::remove(stations.begin(), stations.end(), station), stations.end());

    this->gameScreen->setStations(stations);
}

/**Add a new worker to the factory's worker list*/
void Factory::addWorker(Worker* worker)
{
    workers[worker->getName()]=worker;
}

void Factory::addWorkerToStation(int currentWS, string worker)
{
    stations[currentWS]->assignWorker(workers[worker]);
}

void Factory::removeWorkerFromAnyStation(string workername)
{
    for(auto &station: stations)
    {
        station->removeWorker(workername);
    }
}

/**Remove a worker for the Factory's worker list given the worker.*/
void Factory::removeWorker(Worker* worker)
{
    removeWorker(worker->getName());

}

/**Remove a worker from the Factory's worker list given a worker name*/
void Factory::removeWorker(string workerName)
{
    removeWorkerFromAnyStation(workerName);
    workers.erase(workerName);
}

/**Returns the day count*/
int Factory::getDayCount()
{
    return dayCount;
}

/**Changes the worker moral to 'moral'*/
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

/**Stops a random work station*/
void Factory::stopWorkstation()
{
    if(stations.size())
    {
        int randStation = rand() % stations.size();

        stations[randStation]->setWorking(false);
    }
}

/**Kills a worker*/
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

/**Sets the wage of all employees*/
void Factory::setWage(double wage)
{
    for(auto &worker : workers)
    {
        worker.second->setWagePerDay(wage);
    }
}

/**Creates new employees in a pop up*/
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

/**Creates a pop up with fired employees( to re-hire them)*/
void Factory::addingOldWorker(const QString& s)
{
    int i = findWorkerByName(firedEmps, s);
    Worker* w = firedEmps.at(i);
    firedEmps.erase(std::remove(firedEmps.begin(), firedEmps.end(), w), firedEmps.end());
    rehireWindow->updateFiredWorkers(firedEmps);
    addNewHire(w);
    rehireWindow->updateEmployees(workers);

}

/**Adds a new employee to the Factory's worker list*/
void Factory::addNewHire(Worker* w)
{
    addWorker(w);
    gameScreen->updateWorkers(workers);
    gameScreen->displayWorkerDetails(w);

}

/**Re-hires a fired employee*/
void Factory::hiringOldEmps()
{
    rehireWindow = new ReHireWindow();
    /**Connecting various buttons to methods*/
    connect(rehireWindow,SIGNAL(rehiring(const QString&)),this, SLOT(addingOldWorker(const QString&)));
    connect(rehireWindow,SIGNAL(checkFiredWorkerDetails(const QString&)), this, SLOT(findFiredWorker(const QString&)));
    connect(rehireWindow,SIGNAL(compareWorkers(const QString&, const QString&)), this, SLOT(comparingWorkers(const QString&, const QString&)));
    rehireWindow->updateFiredWorkers(firedEmps);
    rehireWindow->updateEmployees(workers);
    rehireWindow->exec();
}

/**Compares two workers to each other*/
void Factory::comparingWorkers(const QString& s1, const QString& s2)
{
    int i = findWorkerByName(firedEmps, s1);
    //int j = findWorkerByName(workers, s2);
    Worker* w1 = firedEmps.at(i);
    Worker* w2 = workers[s2.toStdString()];
    string compared = w1->compareWorkers(w2);
    rehireWindow->updateComparedWorkersWindow(QString::fromStdString(compared));
}

/**Finds a fired worker by a name given 's'*/
void Factory::findFiredWorker(const QString& s)
{
    int i = findWorkerByName(firedEmps, s);
    Worker* w = firedEmps.at(i);
    rehireWindow->updateDetailsView(w);
}

/**Displays the details of a worker*/
void Factory::checkWorkerDetails(const QString& s)
{
    Worker* w = workers[s.toStdString()];
    gameScreen->displayWorkerDetails(w);

}

/**Fires an unwanted worker*/
void Factory::firingWorker(const QString& s)
{
    workers[s.toStdString()]->setMoral(-3);
    firedEmps.push_back(workers[s.toStdString()]);
    removeWorker(s.toStdString());
    gameScreen->updateWorkers(workers);
}

/**Finds a worker in 'list' given a name 's'*/
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

/**Returns the pointer to the game Screen*/
GameScreen* Factory::getGameScreen()
{
    return gameScreen;
}

/**Upgrades the Factory level*/
void Factory::upgradeFactory()
{
    if(money > factoryUpgradeCost)
    {
        factoryLevel++;
        money -= factoryUpgradeCost;
        factoryUpgradeCost = factoryUpgradeCost * 2;
        gameScreen->displayUpgrade(true, factoryLevel, money, factoryUpgradeCost) ;
        this->gameScreen->updateProductList(Factory::db.getProductNames(factoryLevel));
        if(factoryLevel % 5 == 0 && factoryLevel < 21)
        {
            addFloor();
        }
    }
    else
    {
        gameScreen->displayUpgrade(false, factoryLevel, money, factoryUpgradeCost);
    }
}

/**updates the level of a selected product*/
void Factory::upgradeProduct(string name){
        Factory::db.upgradeProduct(name);
}
