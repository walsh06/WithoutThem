#include "Product.h"

Product::Product(string name, string type, int materialCost, int timeCost, int value)
{
    this->name = name;
    this->type = type;
    this->materialCost = materialCost ;
    this->timeCost = timeCost;
    this->value = value;
}

string Product::getName()
{
    return this->name;
}

string Product::getType()
{
    return this->type;
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
