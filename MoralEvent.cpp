#include "MoralEvent.h"

MoralEvent::MoralEvent(string description, int triggerFactor, int moralChange)
{
    this->description = description;
    this->triggerFactor = triggerFactor;
    this->moralChange = moralChange;
    this->startingTriggerFactor = triggerFactor;
    startDayCount = 0;
}

/** update the events trigger factor*/
void MoralEvent::update(Factory* factory)
{
    int days = factory->getDayCount();

    triggerFactor+= (days - startDayCount) * 2;
}

/** triggers the event and causes effects */
void MoralEvent::trigger(Factory* factory)
{
    //print the event to console
    Printer::printEvent(description);
    //cause pop up
    factory->getGameScreen()->eventPopup(description);
    //change the morale of a worker in the factory
    factory->changeWorkerMoral(moralChange);
    //reset the trigger factor
    triggerFactor = startingTriggerFactor;
    startDayCount = factory->getDayCount();
}

/** returns the trigger factor */
int MoralEvent::getTriggerFactor()
{
    return triggerFactor;
}
