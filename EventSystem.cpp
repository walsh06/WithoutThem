#include "EventSystem.h"
#include "pugixml.hpp"

EventSystem::EventSystem()
{

    readXML();
    srand(time(0));
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

void EventSystem::readXML()
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("events.xml");

    for (pugi::xml_node event: doc.child("events"))
    {
        std::map<string, string> eventMap;
        for (pugi::xml_attribute attr: event.attributes())
        {
             eventMap[attr.name()] = attr.value();
        }

       addEvent(createEvent(eventMap));
    }
}

GameEvent* EventSystem::createEvent(std::map<string, string> event)
{
    GameEvent* newEvent;
    if(event["type"] == "Death")
    {
        newEvent = new DeathEvent(event["description"], stoi(event["trigger"]));
    }
    else if(event["type"] == "Money")
    {
        newEvent = new MoneyEvent(event["description"], stoi(event["trigger"]),event["triggerChange"],stod(event["change"]));
    }
    else if(event["type"] == "Moral")
    {
        newEvent = new MoralEvent(event["description"], stoi(event["trigger"]),stod(event["change"]));
    }

    return newEvent;
}

