#include "Worker.h"

Worker::Worker(string name)
{
    this->name = name;
    nextLevel = 10;
    xp = 0;
    srand(time(0));
    wagePerDay = 6.50;
}

string Worker::getName()
{
    return this->name;
}

StatsList Worker::getStats()
{
    return this->stats;
}

double Worker::getWagePerDay()
{
    return wagePerDay;
}

void Worker::setWagePerDay(double wage)
{
    wagePerDay = wage;
}

void Worker::levelUp()
{
    int statIncrease = rand() % 3;

    nextLevel = nextLevel * 2;
    xp = 0;
}
