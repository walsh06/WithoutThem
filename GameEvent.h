#ifndef GAMEEVENT_H
#define GAMEEVENT_H

#include "Factory.h"
#include <string>

class Factory;

class GameEvent
{
    public:
        virtual void update(Factory* factory) = 0;
        virtual void trigger(Factory* factory) = 0;
        virtual int getTriggerFactor() = 0;
};

#endif // GAMEEVENT_H
