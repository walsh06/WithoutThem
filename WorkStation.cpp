#include "WorkStation.h"
#include "SkillTypeEnums.h"

using namespace skills;

WorkStation::WorkStation(Product* p)
{
    this->product = p;
    numWorkers = 0;
    maxWorkers = 4;
    dailyCount = 0;
    srand(time(0));
}

void WorkStation::makeProduct()
{
    dailyCount++;

}

int WorkStation::getDailyCount()
{
    return dailyCount;
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
        workerSkill += worker->getSkill(type);
    }

    time = time - workerSkill + (rand() % 10);
    return time < 1? 1 : time ;
}


