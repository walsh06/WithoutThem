#ifndef WORKER_H
#define WORKER_H

#include <stdlib.h>
#include <time.h>
#include <string>
#include "StatsList.h"
#include "WorkerBackground.h"
#include "SkillTypeEnums.h"

using namespace skills;
using namespace std;

class Worker
{
public:
    Worker(string name);

    double getWagePerDay();
    void setWagePerDay(double wage);
    string getName();
    StatsList getStats();
    void setStatsList(StatsList stats);
    int getMoral();
    void setMoral(int m);
    void levelUp();
    void gainXP(int xp);

    int getSkill(skillsType type);
    bool isWorking();
    void setWorking(bool working);
    string printWorker();
    WorkerBackground getBackground();
    void setBackground(WorkerBackground background);
    string compareWorkers(Worker* w);
private:
    WorkerBackground background;
    bool working;
    int moral;
    string name;
    //TO DO: int age; Age may need to factor in time and birthdays,
    StatsList stats;
    int xp, nextLevel;
    double wagePerDay;
};

#endif // WORKER_H
