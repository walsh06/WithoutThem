#include "Worker.h"

Worker::Worker(string name)
{
    this->name = name;
    nextLevel = 10;
    xp = 0;
    srand(time(0));
}

string Worker::getName()
{
    return this->name;
}

StatsList Worker::getStats()
{
    return this->stats;
}

void Worker::levelUp()
{
    stats.setMachinerySkill(stats.getMachinerySkill() + rand() % 3);
    stats.setTextileSkill(stats.getTextileSkill() + rand() % 3);

    nextLevel = nextLevel * 2;
    xp = 0;
}

void Worker::gainXP(int xp)
{
    this->xp += xp;
}
