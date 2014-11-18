#ifndef WORKSTATION_H
#define WORKSTATION_H

#include <vector>
#include <stdlib.h>
#include <time.h>

#include "Worker.h"
#include "Product.h"

class WorkStation
{
public:
    WorkStation(Product* p);

    void makeProduct();
    void assignWorker(Worker* worker);
    void removeWorker(Worker* worker);
    int getDailyCount();

    int calcTime();
private:
    vector<Worker*> workers;
    Product *product;

    int dailyCount;
    int maxWorkers;
    int numWorkers;

};

#endif // WORKSTATION_H
