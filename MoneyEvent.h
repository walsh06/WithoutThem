#ifndef MONEYEVENT_H
#define MONEYEVENT_H

#include "GameEvent.h"
#include "EventStrategy.h"

class MoneyEvent: public GameEvent
{
    //Event class that causes a change in money in the factory
public:
    static const int DAYCHANGE = 1, MORALCHANGE = 2;
    MoneyEvent(string description, int triggerFactor, string triggerChange, double moneyChange);
    void update(Factory* factory);
    void trigger(Factory* factory);
    int getTriggerFactor();
private:
    int triggerFactor;
    string description;
    double moneyChange;

    EventStrategy* updateStrategy;
};

#endif // MONEYEVENT_H
