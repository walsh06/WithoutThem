#include "StatsList.h"

StatsList::StatsList()
{
    this->machinery = 1;
    this->textile = 1;
    this->farming = 0;
    this->building = 0;
    this->carpentry = 0;
}

int StatsList::getMachinerySkill()
{
    return this->machinery;
}

int StatsList::getTextileSkill()
{
    return this->textile;
}


int StatsList::getFarmingSkill()
{
    return this->farming;
}

int StatsList::getCarpentrySkill()
{
    return this->carpentry;
}

int StatsList::getBuildingSkill()
{
    return this->building;
}

void StatsList::setTextileSkill(int n)
{
    this->textile = n;
}

void StatsList::setMachinerySkill(int n)
{
    this->machinery = n;
}

void StatsList::setFarmingSkill(int n)
{
    this->farming = n;
}

void StatsList::setCarpentrySkill(int n)
{
    this->carpentry = n;
}

void StatsList::setBuildingSkill(int n)
{
    this->building = n;
}

StatsList StatsList::operator+(const StatsList& stats)
{
    StatsList newstats;
    newstats.machinery = this->machinery + stats.machinery;
    newstats.textile = this->textile + stats.textile;
    newstats.farming = this->farming + stats.farming;
    newstats.carpentry = this->carpentry + stats.carpentry;
    newstats.building = this->building + stats.building;
    return newstats;
}
