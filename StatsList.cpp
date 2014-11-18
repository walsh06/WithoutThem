#include "StatsList.h"

StatsList::StatsList()
{
    this->machinery = 1;
    this->textile = 1;
}

int StatsList::getMachinerySkill()
{
    return this->machinery;
}

int StatsList::getTextileSkill()
{
    return this->textile;
}

void StatsList::setTextileSkill(int n)
{
    this->textile = n;
}

void StatsList::setMachinerySkill(int n)
{
    this->machinery = n;
}

StatsList StatsList::operator+(const StatsList& stats)
{
    StatsList newstats;
    newstats.machinery = this->machinery + stats.machinery;
    newstats.textile = this->textile + stats.textile;
    return newstats;
}
