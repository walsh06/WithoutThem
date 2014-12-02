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
#include "GenerateWorker.h"
#include "WorkStation.h"
#include "QTimer"
#include <iomanip>
#include "GameScreen.h"
#include "Popup.h"


class EventSystem;
using namespace std;
class Factory : public QObject
{
    Q_OBJECT

public:
    Factory(GameScreen* gameScreen); //TO DO find out why this won't work as not pointer

    void addStation(WorkStation* station);
    void removeStation(WorkStation* station);
    void addWorker(Worker* worker);
    void removeWorker(Worker* worker);

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
    Popup* popup;
    vector<Worker *> workers;
    vector<Worker *> nw;
    double money;
    vector<WorkStation *> stations;
    QTimer *timer;
    EventSystem* eventSystem;
    int dayCount;

    GameScreen* gameScreen;
public slots:
    void hireNewEmps();
    void checkWorkerDetails(const QString& s);
    void firingWorker(const QString&s);
    void startDay();
    void setWage(double wage);
    void addNewHire(Worker* w);
private slots:

    void endDay();

};

#endif // FACTORY_H
