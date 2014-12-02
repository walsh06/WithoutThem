#include "MoralEvent.h"

MoralEvent::MoralEvent(string description, int triggerFactor, int moralChange)
{
    this->description = description;
    this->triggerFactor = triggerFactor;
    this->moralChange = moralChange;
    this->startingTriggerFactor = triggerFactor;
    startDayCount = 0;
}

void MoralEvent::update(Factory* factory)
{
    int days = factory->getDayCount();

    triggerFactor+= (days - startDayCount) * 2;
}

void MoralEvent::trigger(Factory* factory)
{
    Printer::printEvent(description);
    factory->getGameScreen()->eventPopup(description);
    factory->changeWorkerMoral(moralChange);
    triggerFactor = startingTriggerFactor;
    startDayCount = factory->getDayCount();
}

int MoralEvent::getTriggerFactor()
{
    return triggerFactor;
}
