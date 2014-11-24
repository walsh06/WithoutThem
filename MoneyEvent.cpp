#include "MoneyEvent.h"

MoneyEvent::MoneyEvent(string description, int triggerFactor, string triggerChange, double moneyChange)
{
    this->description = description;
    this->triggerFactor = triggerFactor;
    this->moneyChange = moneyChange;

    if(triggerChange == "moral")
    {
        //updateStrategy = new MoralStrategy();
    }
    else
    {
        //updateStrategy = new DayStrategy();
    }
}

void MoneyEvent::update(Factory* factory)
{
    //updateStrategy->update(factory);
    //cout << "UPDATE" << endl;
}

void MoneyEvent::trigger(Factory* factory)
{
    Printer::printEvent(description);
    factory->setMoney(factory->getMoney() + moneyChange);
}

int MoneyEvent::getTriggerFactor()
{
    return triggerFactor;
}
