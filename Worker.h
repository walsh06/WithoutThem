#ifndef WORKER_H
#define WORKER_H

#include <stdlib.h>
#include <time.h>
#include <string>
#include "StatsList.h"

using namespace std;

class Worker
{
public:
    Worker(string name);

    double getWagePerDay();
    void setWagePerDay(double wage);
    string getName();
    StatsList getStats();
    //int getAge();
    void levelUp();



private:
    string name;
    //TO DO: int age; Age may need to factor in time and birthdays,
    StatsList stats;
    int xp, nextLevel;
    double wagePerDay;
};

#endif // WORKER_H
