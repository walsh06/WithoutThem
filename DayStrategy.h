#ifndef DAYSTRATEGY_H
#define DAYSTRATEGY_H

#include "EventStrategy.h"
class DayStrategy : public EventStrategy
{
    /**Strategy used in event system
     * Updates the trigger factor of an event according to the days passed
     * unused currently
     */

public:
    DayStrategy();
    int update(Factory* factory, int triggerFactor);
private:

};

#endif // DAYSTRATEGY_H
