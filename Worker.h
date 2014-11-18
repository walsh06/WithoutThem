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

    string getName();
    StatsList getStats();
    //int getAge();
    void levelUp();
    int getSkill(skillsType type);



private:
    skillsType type;
    string name;
    //TO DO: int age; Age may need to factor in time and birthdays,
    StatsList stats;
    int xp, nextLevel;
};

#endif // WORKER_H
