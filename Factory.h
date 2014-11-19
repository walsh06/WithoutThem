#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <vector>

#include "Worker.h"
#include "StatsList.h"
#include "Product.h"
#include "WorkStation.h"
#include "QTimer"
#include <iomanip>

using namespace std;
class Factory : public QObject
{
    Q_OBJECT

public:
    Factory(); //TO DO find out why this won't work as not pointer

    void addStation(WorkStation* station);
    void removeStation(WorkStation* station);

    double getMoney();
    double calcGrossIncome();
    double calcWages();
    double calcNetIncome();

private:
    //TO DO:
    //Add Current Product
    //Extra:
    //multiple products/product list

    //TO DO:
    //Add Worker List
    vector<Worker *> workers;
    double money;
    vector<WorkStation *> stations;
    QTimer *timer;

public slots:

    void startDay();

private slots:

    void endDay();

};

#endif // FACTORY_H
