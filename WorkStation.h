#ifndef WORKSTATION_H
#define WORKSTATION_H

#include <vector>
#include <stdlib.h>
#include <time.h>

#include <QTimer>

#include <QtCore/QObject>

#include "Worker.h"
#include "Product.h"

#include "DatabaseManipulator.h"

#include <iostream>

using namespace std;

class WorkStation : public QObject
{
    Q_OBJECT

public:
    WorkStation(Product* p);

    WorkStation(string s);


    void assignWorker(Worker* worker);
    void removeWorker(Worker* worker);
    int getDailyCount();

    Product* getProduct();

    int calcTime();

    void start();
    void stop();

    bool isWorking();
    void setWorking(bool working);

    QTimer *timer;

private:
    vector<Worker*> workers;
    Product *product;

    int dailyCount;
    int maxWorkers;
    int numWorkers;

    int remainingTime;
    DatabaseManipulator db;

    bool working;

public slots:

    void makeProduct();

    void addProduct();


};

#endif // WORKSTATION_H
