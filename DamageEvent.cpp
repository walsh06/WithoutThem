#include "DamageEvent.h"

/** DamageEvent constructor */
DamageEvent::DamageEvent(string description, int triggerFactor)
{
    this->description = description;
    this->triggerFactor = triggerFactor;
    this->startingTriggerFactor = triggerFactor;
    this->startDayCount = 0;
}

/** update the events trigger factor*/
void DamageEvent::update(Factory* factory)
{
    //update the trigger factor with the days passed
    int days = factory->getDayCount();

    triggerFactor+= (days - startDayCount);
}

/** triggers the event and causes effects */
void DamageEvent::trigger(Factory* factory)
{
    //print the event to console
    Printer::printEvent(description);
    //cause pop up
    factory->getGameScreen()->eventPopup(description);
    //factory->stopWorkstation();
    //reset the trigger factor
    triggerFactor = startingTriggerFactor;
    startDayCount = factory->getDayCount();
}

/** returns the trigger factor */
int DamageEvent::getTriggerFactor()
{
    return triggerFactor;
}
