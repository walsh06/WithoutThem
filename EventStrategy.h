#ifndef EVENTSTRATEGY_H
#define EVENTSTRATEGY_H

#include "Factory.h"
class EventStrategy
{
    /*Event Strategy interface
     * Each event would hold a reference to this interface
     * unused currently
    */
public:
    virtual int update(Factory* factory) = 0;
};

#endif // EVENTSTRATEGY_H
