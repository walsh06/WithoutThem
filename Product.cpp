#include "Product.h"
#include "SkillTypeEnums.h"

Product::Product(string name, skills::skillsType skill, int materialCost,
                 int timeCost, string materialNeeded, int value)
{
    this->name = name;
    this->skill = skill;
    this->materialCost = materialCost ;
    this->timeCost = timeCost;
    this->value = value;
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
    return this->timeCost;
}

int Product::getValue()
{
    return this->value;
}

string Product::getMaterialNeeded()
{
    return materialNeeded;
}
