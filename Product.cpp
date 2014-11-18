#include "Product.h"
#include "SkillTypeEnums.h"

Product::Product(string name, skills::skillsType skill, int materialCost,
                 int timeCost, string materialNeeded)
{
    this->name = name;
    this->skill = skill;
    this->materialCost = materialCost ;
    this->timeCost = timeCost;
    this->materialNeeded = materialNeeded;
}

string Product::getName()
{
    return this->name;
}

skills::skillsType Product::getSkillType()
{
    return this->skill;
}

int Product::getMaterialCost()
{
    return this->materialCost;
}

int Product::getTimeCost()
{
    return this->getTimeCost();
}

string Product::getMaterialNeeded()
{
    return materialNeeded;
}
