#include "WorkerBackground.h"

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

int WorkerBackground::getAge()
{
    return this->age;
}

int WorkerBackground::getNumChildren()
{
    return this->numChildren;
}

int WorkerBackground::getNumSiblings()
{
    return this->numSiblings;
}

bool WorkerBackground::hasHusband()
{
    return this->husband;
}
