#include "Product.h"

Product::Product(string name, string type, int materialCost, int timeCost)
{
    this->name = name;
    this->type = type;
    this->materialCost = materialCost ;
    this->timeCost = timeCost;
    this->xp = 1;
}

string Product::getName()
{
    return this->name;
}

string Product::getType()
{
    return this->type;
}

int Product::getXP()
{
    return xp;
}

int Product::getMaterialCost()
{
    return this->materialCost;
}

int Product::getTimeCost()
{
    return this->getTimeCost();
}
