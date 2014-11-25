#include "Factory.h"
#include "EventSystem.h"
Factory::Factory()
{
    this->money = 1000.00;


    this->timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(endDay()));
    eventSystem = new EventSystem();
    dayCount = 0;
    srand(time(0));

}

void Factory::startDay()
{
    dayCount++;
    cout << "Start of day" << endl;

    eventSystem->update(this);

    for(auto &station : stations)
    {
        station->start();
    }

    cout << money << endl;
    timer->start(6000);
}

void Factory::endDay()
{
    for(auto &station : stations)
    {
        station->stop();
    }

    money += calcNetIncome();

    cout << "End of day" << endl;


   //"TEMP - Testing - restart day - should be done on button click or something" << endl;
    timer->stop();
    startDay();

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
    stations.push_back(station);
}

void Factory::removeStation(WorkStation* station)
{
    //Moves station to the end, erases last station
    stations.erase(std::remove(stations.begin(), stations.end(), station), stations.end());
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
