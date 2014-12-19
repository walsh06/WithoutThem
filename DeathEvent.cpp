#include "DeathEvent.h"

/** Event Constructor */
DeathEvent::DeathEvent(string description, int triggerFactor)
{
    this->description = description;
    this->triggerFactor = triggerFactor;
    this->startingTriggerFactor = triggerFactor;
    this->startDayCount = 0;
}

/** update the events trigger factor*/
void DeathEvent::update(Factory* factory)
{
    //update the trigger factor with the days passed
    int days = factory->getDayCount();

    triggerFactor+= (days - startDayCount);
}

/** triggers the event and causes effects */
void DeathEvent::trigger(Factory* factory)
{
    //print the event to console
    Printer::printEvent(description);
    //cause pop up
    factory->getGameScreen()->eventPopup(description);
    //kill worker in the factory
    factory->killWorker();
    //reset the trigger factor
    triggerFactor = startingTriggerFactor;
    startDayCount = factory->getDayCount();
}

/** returns the trigger factor */
int DeathEvent::getTriggerFactor()
{
    return triggerFactor;
}
