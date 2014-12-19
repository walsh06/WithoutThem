#include "StatsList.h"


/**Creates a new statlist with machinery and textile skill level at 1*/
StatsList::StatsList()
{
    this->machinery = 1;
    this->textile = 1;
    this->farming = 0;
    this->building = 0;
    this->carpentry = 0;
}

/**Returns the Machinery Skill*/
int StatsList::getMachinerySkill()
{
    return this->machinery;
}

/**Returns the Textile Skill*/
int StatsList::getTextileSkill()
{
    return this->textile;
}


/**Returns the Farming Skill*/
int StatsList::getFarmingSkill()
{
    return this->farming;
}

/**Returns the Carpentry Skill*/
int StatsList::getCarpentrySkill()
{
    return this->carpentry;
}

/**Returns the Building Skill*/
int StatsList::getBuildingSkill()
{
    return this->building;
}

/**Sets the Textile Skill*/
void StatsList::setTextileSkill(int n)
{
    this->textile = n;
}

/**Sets the Machinery Skill*/
void StatsList::setMachinerySkill(int n)
{
    this->machinery = n;
}

/**Sets the Farming Skill*/
void StatsList::setFarmingSkill(int n)
{
    this->farming = n;
}

/**Sets the Carpentry Skill*/
void StatsList::setCarpentrySkill(int n)
{
    this->carpentry = n;
}

/**Sets the Building Skill*/
void StatsList::setBuildingSkill(int n)
{
    this->building = n;
}

/**Overloads the '+' operator for statslists*/
StatsList StatsList::operator+(const StatsList& stats)
{
    StatsList newstats;
    newstats.machinery = this->machinery + stats.machinery;
    newstats.textile = this->textile + stats.textile;
    return newstats;
}
