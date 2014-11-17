#ifndef WORKER_H
#define WORKER_H

#include <string>
#include "StatsList.h"

using namespace std;

class Worker
{
public:
    Worker(string name);

    string getName();
    StatsList getStats();
    //int getAge();



private:
    string name;
    //TO DO: int age; Age may need to factor in time and birthdays,
    StatsList stats;
};

#endif // WORKER_H
