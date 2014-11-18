#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <vector>

#include "Worker.h"
#include "StatsList.h"
#include "Product.h"
#include "WorkStation.h"
#include "QTimer"

using namespace std;
class Factory : public QObject
{
    Q_OBJECT

public:
    Factory(); //TO DO find out why this won't work as not pointer

    void addStation(WorkStation* station);
    void removeStation(WorkStation* station);

    int getMoney();
    int calcGrossIncome();
    int calcWages();
    int calcNetIncome();

private:
    //TO DO:
    //Add Current Product
    //Extra:
    //multiple products/product list

    //TO DO:
    //Add Worker List
    vector<Worker *> workers;
    int money;
    vector<WorkStation *> stations;
    QTimer *timer;

private slots:
    void startDay();

    void endDay();

};

#endif // FACTORY_H
