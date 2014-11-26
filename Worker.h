#ifndef WORKER_H
#define WORKER_H

#include <stdlib.h>
#include <time.h>
#include <string>
#include "StatsList.h"
#include "SkillTypeEnums.h"

using namespace skills;
using namespace std;

class Worker
{
public:
    Worker(string name,skillsType type);

    double getWagePerDay();
    void setWagePerDay(double wage);
    string getName();
    StatsList getStats();
    void setStatsList(StatsList stats);
    int getMoral();
    void setMoral(int m);
    //int getAge();
    void levelUp();
    void gainXP(int xp);

    int getSkill(skillsType type);
    bool isWorking();
    void setWorking(bool working);
    void printWorker();
private:
    bool working;
    int moral;
    skillsType type;
    string name;
    //TO DO: int age; Age may need to factor in time and birthdays,
    StatsList stats;
    int xp, nextLevel;
    double wagePerDay;
};

#endif // WORKER_H
