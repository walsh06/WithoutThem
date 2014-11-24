#include "DeathEvent.h"


DeathEvent::DeathEvent(string description, int triggerFactor)
{
    this->description = description;
    this->triggerFactor = triggerFactor;
    this->startingTriggerFactor = triggerFactor;
    this->startDayCount = 0;
}

void DeathEvent::update(Factory* factory)
{
    int days = factory->getDayCount();

    triggerFactor+= (days - startDayCount);
}

void DeathEvent::trigger(Factory* factory)
{
    Printer::printEvent(description);
    factory->killWorker();
    triggerFactor = startingTriggerFactor;
    startDayCount = factory->getDayCount();
}

int DeathEvent::getTriggerFactor()
{
    return triggerFactor;
}
