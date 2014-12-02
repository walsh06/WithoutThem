#include "Factory.h"
#include "iostream"
#include "GenerateWorker.h"
#include "EventSystem.h"
#include "Popup.h"

Factory::Factory(GameScreen* gameScreen)
{
    this->money = 1000.00;


    this->timer = new QTimer(this);


    connect(timer, SIGNAL(timeout()), this, SLOT(endDay()));
    eventSystem = new EventSystem();
    dayCount = 0;
    srand(time(0));
    this->gameScreen = gameScreen;
    this->gameScreen->setStations(stations);
    connect(gameScreen, SIGNAL(updateWage(double)), this, SLOT(setWage(double)));
    connect(gameScreen,SIGNAL(hireEmps()), this, SLOT(hireNewEmps()));
    connect(gameScreen,SIGNAL(checkExistingWorkerDetails(const QString&)), this, SLOT(checkWorkerDetails(const QString&)));
    connect(gameScreen,SIGNAL(fireWorker(const QString&)),this,SLOT(firingWorker(const QString&)));
}

void Factory::startDay()
{
    dayCount++;

    cout << "Start of day" << endl;
    eventSystem->update(this);
    gameScreen->updateFactory(dayCount, money, workers.size());
    gameScreen->updateWorkers(workers);


    for(auto &station : stations)
    {
        station->start();
    }

    timer->start(6000);
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
    startDay();

    // Possibly move to startDay()
    for(auto &worker : workers)
    {
        worker->setWorking(true);
    }

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

    cout << "Income: " << dailyIncome << endl;
    return dailyIncome;
}

double Factory::calcWages()
{
    double dailyWages = 0.00;
    for(auto &worker : workers)
    {
        dailyWages += worker->getWagePerDay();
    }
    cout << "Wages: " << dailyWages << endl;

    return dailyWages;
}

double Factory::calcNetIncome()
{
    double net = calcGrossIncome() - calcWages();
    cout << "net: " << net << endl;

    return net;
}

void Factory::addStation(WorkStation* station)
{
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

int Factory::changeWorkerMoral(int moral)
{
    if(workers.size())
    {
        int randWorker = rand() % workers.size();

        workers[randWorker]->setMoral(moral);
    }
}

int Factory::stopWorkstation()
{
    if(stations.size())
    {
        int randStation = rand() % stations.size();

        stations[randStation]->setWorking(false);
    }
}

int Factory::killWorker()
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

void Factory::addNewHire(Worker *w)
{
    addWorker(w);
    gameScreen->updateWorkers(workers);
    gameScreen->displayWorkerDetails(w);

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
    removeWorker(workers.at(i));
    gameScreen->updateWorkers(workers);
}
