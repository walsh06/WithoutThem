#ifndef DAMAGEEVENT_H
#define DAMAGEEVENT_H

#include "Factory.h"
#include "GameEvent.h"

class DamageEvent : public GameEvent
{
public:
    DamageEvent(string description, int triggerFactor);
    void update(Factory* factory);
    void trigger(Factory* factory);
    int getTriggerFactor();
private:
    int triggerFactor, startingTriggerFactor;
    string description;
    int startDayCount;
};

#endif // DAMAGEEVENT_H
