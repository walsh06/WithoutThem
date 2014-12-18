#ifndef MORALEVENT_H
#define MORALEVENT_H

#include "Factory.h"
#include "GameEvent.h"

class MoralEvent: public GameEvent
{
    //Event class that causes a change in morale in workers
public:
    MoralEvent(string description, int triggerFactor, int moralChange);
    void update(Factory* factory);
    void trigger(Factory* factory);
    int getTriggerFactor();
private:
    int triggerFactor, startingTriggerFactor;
    string description;
    int moralChange;
    int startDayCount;
};

#endif // MORALEVENT_H
