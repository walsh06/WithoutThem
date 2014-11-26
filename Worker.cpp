#include "Worker.h"
#include "SkillTypeEnums.h"

#include <iostream>

using namespace skills;

Worker::Worker(string name, skillsType type)
{
    this->name = name;
    this->type = type;
    nextLevel = 5;
    xp = 0;
    srand(time(0));
    wagePerDay = 6.50;
    moral = 1;
    working = true;
}

string Worker::getName()
{
    return this->name;
}

StatsList Worker::getStats()
{
    return this->stats;
}

void Worker::setStatsList(StatsList stats)
{
    this->stats = stats;
}

double Worker::getWagePerDay()
{
    return wagePerDay;
}

void Worker::setWagePerDay(double wage)
{
    wagePerDay = wage;
}

int Worker::getMoral()
{
    return moral;
}

void Worker::setMoral(int m)
{
    if(m = 0)
    {
        this->moral = 1;
    }
    else if(m > 3)
    {
        this->moral = 3;
    }
    else if(m < -3)
    {
        this->moral = -3;
    }
    else
    {
        this->moral = m;
    }
}

void Worker::levelUp()
{
    stats.setMachinerySkill(stats.getMachinerySkill() + rand() % 3);
    stats.setTextileSkill(stats.getTextileSkill() + rand() % 3);
    stats.setFarmingSkill(stats.getFarmingSkill() + rand() % 3);
    stats.setCarpentrySkill(stats.getCarpentrySkill() + rand() % 3);
    stats.setBuildingSkill(stats.getFarmingSkill() + rand() % 3);
    xp = xp - nextLevel;
    nextLevel = nextLevel * 2;

}

void Worker::gainXP(int xp)
{
    this->xp += xp;
    if(this->xp >= nextLevel)
    {
        levelUp();
    }
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
    return -1;
}

bool Worker::isWorking()
{
    return working;
}

void Worker::setWorking(bool working)
{
    this->working=working;
}

void Worker::printWorker()
{
    cout << "Name: " << name << " XP:" << xp<< " Wage per day: " << getWagePerDay() ;
    cout << " Mec:" << stats.getMachinerySkill();
    cout << " Farm:" << stats.getFarmingSkill() <<" Seam:" << stats.getTextileSkill();
    cout << " Build:" << stats.getBuildingSkill() << " Car: "<< stats.getCarpentrySkill() << endl;
}
