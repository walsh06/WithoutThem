#ifndef DEATHEVENT_H
#define DEATHEVENT_H

#include "Factory.h"
#include "GameEvent.h"
class DeathEvent : public GameEvent
{
    //Event class that causes a worker to die
public:
    DeathEvent(string description, int triggerFactor);
    void update(Factory* factory);
    void trigger(Factory* factory);
    int getTriggerFactor();
private:
    int triggerFactor, startingTriggerFactor;
    string description;
    int startDayCount;
};

#endif // DEATHEVENT_H
