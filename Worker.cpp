#include "Worker.h"
#include "WorkerBackground.h"
#include "SkillTypeEnums.h"

#include <iostream>

using namespace skills;

Worker::Worker(string name)
{
    this->name = name;
    nextLevel = 5;
    xp = 0;
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

void Worker::setBackground(WorkerBackground background)
{
    this->background = background;
}

WorkerBackground Worker::getBackground()
{
    return this->background;
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

string Worker::printWorker()
{
    string emp;
    string names = "Name: " + name + "\n Age: " + to_string(background.getAge()) + "\n";
    string child = " Number of children:" + to_string(background.getNumChildren()) + "\n";
    string hus;
    if(background.hasHusband()){
        hus = " Husband: true\n";
    }else{
        hus = " Husband: false\n";
    }
    string sibs = " Number of siblings:" + to_string(background.getNumSiblings()) + "\n";
    string exp = " XP:" + to_string(xp) + "\n" + " Wage per day: "
                 + to_string(getWagePerDay()) + "\n";
    string mec = " Mec:" + to_string(stats.getMachinerySkill()) + "\n";
    string farm = " Farm:" + to_string(stats.getFarmingSkill()) + "\n"
                + " Seam:" + to_string(stats.getTextileSkill()) + "\n";
    string build = " Build:" + to_string(stats.getBuildingSkill()) + "\n"
                   + " Car: " + to_string(stats.getCarpentrySkill()) + "\n";
    return emp = names + child + hus + sibs + exp + mec + farm + build;
}
