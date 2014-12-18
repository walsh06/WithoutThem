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
    /*Event System class
     * Maintains list of events
     * Manages all events by updating and triggering events at random intervals
    */
public:
    EventSystem();

    void update(Factory *factory);
    void addEvent(GameEvent* event);
    void removeEvent(GameEvent* event);
private:
    void readXML();
    std::vector<GameEvent *> events;
    GameEvent* createEvent(std::map<string, string> event);
};

#endif // EVENTSYSTEM_H
