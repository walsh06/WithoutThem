#ifndef EVENTSTRATEGY_H
#define EVENTSTRATEGY_H

#include "Factory.h"
class EventStrategy
{
public:
    virtual int update(Factory* factory) = 0;
};

#endif // EVENTSTRATEGY_H
