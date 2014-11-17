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

StatsList StatsList::operator+(const StatsList& stats)
{
    StatsList newstats;
    newstats.machinery = this->machinery + stats.machinery;
    newstats.textile = this->textile + stats.textile;
    return newstats;
}
