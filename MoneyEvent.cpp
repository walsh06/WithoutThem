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

/** update the events trigger factor*/
void MoneyEvent::update(Factory* factory)
{
    //updateStrategy->update(factory);
    //cout << "UPDATE" << endl;
}

/** triggers the event and causes effects */
void MoneyEvent::trigger(Factory* factory)
{
    //print the event to console
    Printer::printEvent(description);
    //cause pop up
    factory->getGameScreen()->eventPopup(description);
    //update the money
    factory->setMoney(factory->getMoney() + moneyChange);
}

/** returns the trigger factor */
int MoneyEvent::getTriggerFactor()
{
    return triggerFactor;
}
