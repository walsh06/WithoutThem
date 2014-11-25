#include "DamageEvent.h"

DamageEvent::DamageEvent(string description, int triggerFactor)
{
    this->description = description;
    this->triggerFactor = triggerFactor;
    this->startingTriggerFactor = triggerFactor;
    this->startDayCount = 0;
}

void DamageEvent::update(Factory* factory)
{
    int days = factory->getDayCount();

    triggerFactor+= (days - startDayCount);
}

void DamageEvent::trigger(Factory* factory)
{
    Printer::printEvent(description);
    factory->stopWorkstation();
    triggerFactor = startingTriggerFactor;
    startDayCount = factory->getDayCount();
}

int DamageEvent::getTriggerFactor()
{
    return triggerFactor;
}
