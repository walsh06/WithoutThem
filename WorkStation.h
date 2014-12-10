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

    WorkStation();

    WorkStation(Product* p);

    WorkStation(string s);


    void assignWorker(Worker* worker);
    void assignWorker(string workerName);
    void removeWorker(Worker* worker);
    void removeWorker(string workerName);
    int getDailyCount();
    int getNumWorkers();

    Product* getProduct();
    void setProduct(string product);

    int calcTime();

    void start();
    void stop();

    bool isWorking();
    void setWorking(bool working);

    QTimer *timer;

private:
    map<string, Worker*> workers;
    Product *product;

    int dailyCount;
    int maxWorkers;
    int numWorkers;

    int remainingTime;

    bool working;


public slots:

    void makeProduct();

    void addProduct();

signals:
    void updateWS();



};

#endif // WORKSTATION_H
