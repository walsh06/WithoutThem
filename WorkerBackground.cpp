#include "WorkerBackground.h"


/**Creates a background object for the worker*/
WorkerBackground::WorkerBackground()
{
    this->numChildren = rand() % 6;
    this->age = (rand() % 25) + 25;
    this->numSiblings = rand() % 3;
    if(rand() % 2){
        this->husband = true;
    }else{
        this->husband = false;
    }
}

/**Returns an int representing the workers age*/
int WorkerBackground::getAge()
{
    return this->age;
}

/**Returns an int representing the number of children*/
int WorkerBackground::getNumChildren()
{
    return this->numChildren;
}

/**Returns an int representing the number of siblings*/
int WorkerBackground::getNumSiblings()
{
    return this->numSiblings;
}

/**Returns if the worker has a spouse or not.*/
bool WorkerBackground::hasHusband()
{
    return this->husband;
}
