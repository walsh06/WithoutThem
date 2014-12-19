#include "EventSystem.h"
#include "pugixml.hpp"

/** EventSystem Constructor */
EventSystem::EventSystem()
{
    readXML();
    srand(time(0));
}

/** Update called at the end of each day
 * Updates all events in the system
 * */
void EventSystem::update(Factory *factory)
{
    //update each event
    for(auto &event: events)
    {
        event->update(factory);
    }

    //1 in 5 chance of an event happening
    int ran = rand() % 5;

    if(ran == 0)
    {
        //get all trigger factors and put them into an array
        int total = 0, size = events.size();
        int triggers[size];

        for(int i =0; i < size; i++)
        {
            total += events[i]->getTriggerFactor();
            triggers[i] = total;
        }

        //Get a random value of the event to trigger
        ran = rand() % total;

        //find the corresponding event and trigger it
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

/** Add a new Event to the System */
void EventSystem::addEvent(GameEvent* event)
{
    events.push_back(event);
}

/** Remove an event from the system */
void EventSystem::removeEvent(GameEvent* event)
{
    events.erase(std::remove(events.begin(), events.end(), event), events.end());
}

/** Read the events.xml file and file the event system */
void EventSystem::readXML()
{
    //open the document
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("../WithoutThem/events.xml");

    //loop through the tree structure created of the xml
    for (pugi::xml_node event: doc.child("events"))
    {
        //for each event get all the attributes and store in a map
        std::map<string, string> eventMap;
        for (pugi::xml_attribute attr: event.attributes())
        {
             eventMap[attr.name()] = attr.value();
        }

       // pass the map to the createEvent method and add it to the events list
       addEvent(createEvent(eventMap));
    }
}

/** Creates a new Event from a map of attributes */
GameEvent* EventSystem::createEvent(std::map<string, string> event)
{
    //Declare a new event
    GameEvent* newEvent;
    //find the correct sub class of Game Event
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

    //return the new event
    return newEvent;
}

