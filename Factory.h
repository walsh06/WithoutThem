#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

//#include "EventSystem.h"
#include "Worker.h"
#include "StatsList.h"
#include "Product.h"
#include "WorkStation.h"
#include "QTimer"
#include <iomanip>
#include "GameScreen.h"


class EventSystem;
using namespace std;
class Factory : public QObject
{
    Q_OBJECT

public:
    Factory(GameScreen* gameScreen); //TO DO find out why this won't work as not pointer

    void addStation(WorkStation* station);
    void removeStation(WorkStation* station);

    double getMoney();
    void setMoney(double money);
    double calcGrossIncome();
    double calcWages();
    double calcNetIncome();
    int getDayCount();
    int changeWorkerMoral();

    int changeWorkerMoral(int moral);
    int stopWorkstation();
    int killWorker();

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
    EventSystem* eventSystem;
    int dayCount;

    GameScreen* gameScreen;
public slots:

    void startDay();

private slots:

    void endDay();

};

#endif // FACTORY_H
