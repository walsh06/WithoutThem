#include "MoneyEvent.h"

MoneyEvent::MoneyEvent(string description, int triggerFactor, double moneyChange)
{
    this->description = description;
    this->triggerFactor = triggerFactor;
    this->moneyChange = moneyChange;
}

void MoneyEvent::update(Factory* factory)
{

}

void MoneyEvent::trigger(Factory* factory)
{
    cout << description << endl;
    factory->setMoney(factory->getMoney() + moneyChange);
}

int MoneyEvent::getTriggerFactor()
{
    return triggerFactor;
}
