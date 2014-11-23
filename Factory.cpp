#include "Factory.h"

Factory::Factory()
{
    this->money = 1000.00;


    this->timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(endDay()));

}

void Factory::startDay()
{
    cout << "Start of day" << endl;
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
}

double Factory::getMoney()
{
    return money;
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
