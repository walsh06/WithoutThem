#include "Worker.h"

Worker::Worker(string name)
{
    this->name = name;
}

string Worker::getName()
{
    return this->name;
}

StatsList Worker::getStats()
{
    return this->stats;
}
