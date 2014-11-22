#ifndef MONEYEVENT_H
#define MONEYEVENT_H

#include "GameEvent.h"

class MoneyEvent: public GameEvent
{
public:
    MoneyEvent(string description, int triggerFactor, double moneyChange);
    void update(Factory* factory);
    void trigger(Factory* factory);
    int getTriggerFactor();
private:
    int triggerFactor;
    string description;
    double moneyChange;
};

#endif // MONEYEVENT_H
