#include "EventSystem.h"

EventSystem::EventSystem()
{
    srand(time(0));
    addEvent(new MoneyEvent("Received money from government", 20, 100.00));
    addEvent(new MoneyEvent("Shipment destroyed", 50, -100.00));
    addEvent(new MoralEvent("Death in the family", 10, -3));
    addEvent(new DeathEvent("Worker died in air raid", 5));
}


void EventSystem::update(Factory *factory)
{
    for(auto &event: events)
    {
        event->update(factory);
    }

    int ran = rand() % 5;

    if(ran == 0)
    {
        int total = 0, size = events.size();
        int triggers[size];

        for(int i =0; i < size; i++)
        {
            total += events[i]->getTriggerFactor();
            triggers[i] = total;
        }

        ran = rand() % total;

        for(int i =0; i < size; i++)
        {
            if(ran <triggers[i])
            {
                events[i]->trigger(factory);
                break;
            }
        }
    }
}


void EventSystem::addEvent(GameEvent* event)
{
    events.push_back(event);
}

void EventSystem::removeEvent(GameEvent* event)
{
    events.erase(std::remove(events.begin(), events.end(), event), events.end());
}

