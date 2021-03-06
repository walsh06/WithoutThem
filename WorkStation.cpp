#include "WorkStation.h"
#include "SkillTypeEnums.h"
#include "Factory.h"

using namespace skills;
WorkStation::WorkStation()
{

    this->product = new Product("N/A", skillsType::NONE, -1, -1, "N/A", -1, -1);
    numWorkers = 0;
    maxWorkers = 4;
    dailyCount = 0;
    srand(time(0));
    remainingTime = 0;

    this->timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(addProduct()));
    working = false;
}


WorkStation::WorkStation(string s)
{
    WorkStation();
    this->setProduct(s);
}



int WorkStation::getDailyCount()
{
    return dailyCount;
}


int WorkStation::getNumWorkers()
{
    return this->numWorkers;
}

Product* WorkStation::getProduct()
{
    return product;
}

void WorkStation::setProduct(string product)
{
    this->product = Factory::db.getProduct(product);
    this->timer->stop();
    this->makeProduct();
}

void WorkStation::assignWorker(Worker* worker)
{
    if(numWorkers + 1 <= maxWorkers)
    {
       workers[worker->getName()] = worker;
        numWorkers++;
    }

    if(numWorkers == 1)
    {
        working = true;
        makeProduct();
    }
}

void WorkStation::removeWorker(Worker* worker)
{
    workers.erase(worker->getName());
    numWorkers--;


    if(numWorkers < 1)
    {
        working = false;
    }
}

void WorkStation::removeWorker(string workerName)
{
    workers.erase(workerName);
    numWorkers--;


    if(numWorkers < 1)
    {
        working = false;
    }
}

/** Calculates the time to produce a product */
int WorkStation::calcTime()
{
    //get the base time of the product
    int time = product->getTimeCost();

    //get the skill type needed for the product
    skillsType type = product->getSkillType();
    int workerSkill = 0;

    //for each worker in the worker station
    //Get their skill and their morale
    for(auto &value : workers)
    {
        if(value.second->isWorking())
        {
            workerSkill += (value.second->getSkill(type) * value.second->getMoral());
        }
    }

    //get the final time by adding some random noise
    time = time - workerSkill + (rand() % 10);
    return time < 1? 1 : time ;

}

void WorkStation::makeProduct()
{
    if(working && product->getSkillType() != skillsType::NONE)
    {
        int time = 0;
        if(remainingTime > 0){
            time = remainingTime;
            remainingTime = 0;
        }else
            time = calcTime();

        //Creates product every 1/6th of a second
        timer->start(time);
    }
}


void WorkStation::start()
{
    dailyCount = 0;
    makeProduct();
}

void WorkStation::stop()
{
    this->remainingTime = timer->remainingTime();
    timer->stop();
}

void WorkStation::addProduct()
{
    //add 1 to product
    dailyCount++;
    emit updateWS();

    for(auto &value: workers)
    {
        value.second->gainXP(product->getXP());
    }

    //TO DO: Factor in materials etc.

    //call makeProduct again
    makeProduct();
}

bool WorkStation::isWorking()
{
    return working;
}

void WorkStation::setWorking(bool working)
{
    this->working=working;
}






