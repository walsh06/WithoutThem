#ifndef DAYSTRATEGY_H
#define DAYSTRATEGY_H

#include "EventStrategy.h"
class DayStrategy : public EventStrategy
{
public:
    DayStrategy();
    int update(Factory* factory, int triggerFactor);
private:

};

#endif // DAYSTRATEGY_H
