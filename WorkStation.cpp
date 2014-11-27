#include "WorkStation.h"
#include "SkillTypeEnums.h"

using namespace skills;
WorkStation::WorkStation(string s)
{
    this->product = db.getProduct(s);
    numWorkers = 0;
    maxWorkers = 4;
    dailyCount = 0;
    srand(time(0));
    remainingTime = 0;

    this->timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(addProduct()));
    working = true;
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

void WorkStation::assignWorker(Worker* worker)
{
    if(numWorkers + 1 <= maxWorkers)
    {
        workers.push_back(worker);
        numWorkers++;
    }
}

void WorkStation::removeWorker(Worker* worker)
{
    for(int i =0; i < numWorkers; i++)
    {
        if(workers[i] == worker)
        {
            workers.erase(workers.begin() + i);
            numWorkers--;
        }
    }
}

int WorkStation::calcTime()
{
    int time = product->getTimeCost();

    skillsType type = product->getSkillType();
    int workerSkill = 0;
    for(auto &worker : workers)
    {
        if(worker->isWorking())
        {
            workerSkill += (worker->getSkill(type) * worker->getMoral());
        }
    }

    time = time - workerSkill + (rand() % 10);
    return time < 1? 1 : time ;
}

void WorkStation::makeProduct()
{
    if(working)
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

    for(auto &worker: workers)
    {
        worker->gainXP(product->getXP());
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



