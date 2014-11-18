#include "Worker.h"
#include "SkillTypeEnums.h"

using namespace skills;

Worker::Worker(string name, skillsType type)
{
    this->name = name;
    this->type = type;
    nextLevel = 10;
    xp = 0;
    srand(time(0));
}

string Worker::getName()
{
    return this->name;
}

StatsList Worker::getStats()
{
    return this->stats;
}

void Worker::levelUp()
{
    int statIncrease = rand() % 3;

    nextLevel = nextLevel * 2;
    xp = 0;
}

int Worker::getSkill(skillsType type)
{
    if(type == skillsType::MECHANIC){

        return this->stats.getMachinerySkill();

    }else if(type == skillsType::BUILDER){

        return this->stats.getBuildingSkill();

    }else if(type == skillsType::SEAMSTRESS){

        return this->stats.getTextileSkill();

    }else if(type == skillsType::CARPENTER){

        return this->stats.getCarpentrySkill();

    }else if(type == skillsType::FARMER){

        return this->stats.getFarmingSkill();

    }
}
