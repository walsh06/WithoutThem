#include "Worker.h"
#include "WorkerBackground.h"
#include "SkillTypeEnums.h"

#include <iostream>

using namespace skills;

/**Creates a worker with a name*/
Worker::Worker(string name)
{
    this->name = name;
    nextLevel = 5;
    xp = 0;
    wagePerDay = 6.50;
    moral = 1;
    working = true;
}

/**Returns the worker's name*/
string Worker::getName()
{
    return this->name;
}

/**Returns a pointer to the workers statslist*/
StatsList Worker::getStats()
{
    return this->stats;
}

/**Replaces the old statslist with the new one*/
void Worker::setStatsList(StatsList stats)
{
    this->stats = stats;
}

/**Returns the worker's wage per day*/
double Worker::getWagePerDay()
{
    return wagePerDay;
}

/**Sets the workers wage per day*/
void Worker::setWagePerDay(double wage)
{
    wagePerDay = wage;
}

/**Returns a numerical representation of the workers moral*/
int Worker::getMoral()
{
    return moral;
}

/**Sets the workers moral based on the parameter passed in*/
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

/**Sets the background of the worker to the object passed in*/
void Worker::setBackground(WorkerBackground background)
{
    this->background = background;
}

/**Returns the workers background object*/
WorkerBackground Worker::getBackground()
{
    return this->background;
}

/**Levels up the workers skills in their statslist*/
void Worker::levelUp()
{
    //update a workers stats by a random amount
    int upgradeAmount = 3;
    stats.setMachinerySkill(stats.getMachinerySkill() + rand() % upgradeAmount);
    stats.setTextileSkill(stats.getTextileSkill() + rand() % upgradeAmount);
    stats.setFarmingSkill(stats.getFarmingSkill() + rand() % upgradeAmount);
    stats.setCarpentrySkill(stats.getCarpentrySkill() + rand() % upgradeAmount);
    stats.setBuildingSkill(stats.getFarmingSkill() + rand() % upgradeAmount);

    //update the xp needed for the next level
    xp = xp - nextLevel;
    nextLevel = nextLevel * 2;

}

/**Adds the xp gained from working to a workers xp*/
void Worker::gainXP(int xp)
{
    this->xp += xp;
    if(this->xp >= nextLevel)
    {
        levelUp();
    }
}

/**Returns the enum of the workers skill type.*/
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

/**Check if the worker is working at a work station*/
bool Worker::isWorking()
{
    return working;
}

/**Set the worker to work at a work station.*/
void Worker::setWorking(bool working)
{
    this->working=working;
}

/**Compares two workers and their stats*/
string Worker::compareWorkers(Worker* w)
{
   string compared;
   compared = "   " + this->name + " | " + w->getName() + "\n";
   compared += "Mec skills:   " + to_string(stats.getMachinerySkill()) +  "       |       "
              + to_string(w->getStats().getMachinerySkill()) + "\n";
   compared += "Farm skills:  " + to_string(stats.getFarmingSkill()) +  "       |       "
           + to_string(w->getStats().getFarmingSkill()) + "\n";
   compared += "Seam skills: " + to_string(stats.getTextileSkill()) +  "       |       "
           + to_string(w->getStats().getTextileSkill()) + "\n";
   compared += "Build skills:  " + to_string(stats.getBuildingSkill()) +  "       |       "
           + to_string(w->getStats().getBuildingSkill()) + "\n";
   compared += "Car skills:     " + to_string(stats.getCarpentrySkill()) +  "       |       "
           + to_string(w->getStats().getCarpentrySkill()) + "\n";
   return compared;

}

/**Prints the worker details to a string and returns it*/
string Worker::printWorker()
{
    string emp;
    string names = "Name: " + name + "\n Age: " + to_string(background.getAge()) + "\n";
    string child = " Number of children:" + to_string(background.getNumChildren()) + "\n";
    string hus;
    if(background.hasHusband()){
        hus = " Spouse: true\n";
    }else{
        hus = " Spouse: false\n";
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
