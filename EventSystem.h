#ifndef EVENTSYSTEM_H
#define EVENTSYSTEM_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "Factory.h"
#include "MoneyEvent.h"
#include "MoralEvent.h"
#include "DeathEvent.h"
#include "GameEvent.h"

using namespace std;
class EventSystem
{
public:
    EventSystem();

    void update(Factory *factory);
    void addEvent(GameEvent* event);
    void removeEvent(GameEvent* event);
private:
    std::vector<GameEvent *> events;
};

#endif // EVENTSYSTEM_H
