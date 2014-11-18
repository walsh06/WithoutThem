#include "Factory.h"

Factory::Factory()
{
    this->money = 1000;


    this->timer = new QTimer(this);
    startDay();

}

void Factory::startDay()
{
    for(auto &station : stations)
    {
        station->start();
    }

    connect(timer, SIGNAL(timeout()), this, SLOT(endDay()));
    timer->start(100000);
}

void Factory::endDay()
{
    for(auto &station : stations)
    {
        station->stop();
    }

    money += calcNetIncome();


    cout << "TEMP - Testing - restart day - should be done on button click or something";
    startDay();
}

int Factory::getMoney()
{
    return money;
}

int Factory::calcGrossIncome()
{
    int dailyIncome;
    for(auto &station : stations)
    {
        dailyIncome += (station->getProduct()->getValue() * station->getDailyCount());
    }
    return dailyIncome;
}

int Factory::calcWages()
{
    int dailyWages;
    for(auto &worker : workers)
    {
        dailyWages += worker->getWagePerDay();
    }
    return dailyWages;
}

int Factory::calcNetIncome()
{
    int net = calcGrossIncome() - calcWages();
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
