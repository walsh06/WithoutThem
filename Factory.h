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
#include "ReHireWindow.h"


class EventSystem;
using namespace std;
class Factory : public QObject
{
    Q_OBJECT

public:
    Factory(GameScreen* gameScreen);
    static DatabaseManipulator db;
    GameScreen* getGameScreen();

    void addStation(WorkStation* station);
    void removeStation(WorkStation* station);
    void addWorker(Worker* worker);

    void removeWorkerFromAnyStation(string workername);
    void removeWorker(Worker* worker);
    void removeWorker(string workerName);
    double getMoney();
    void setMoney(double money);
    double calcGrossIncome();
    double calcWages();
    double calcNetIncome();
    int getDayCount();
    void changeWorkerMoral();
    void changeWorkerMoral(int moral);
    void stopWorkstation();
    void killWorker();

private:
    Popup* popup;
    ReHireWindow* rehireWindow;
    vector<Worker *> firedEmps, nw;
    map<string, Worker*> workers;
    double money;
    vector<WorkStation *> stations;
    QTimer *timer;
    EventSystem* eventSystem;
    int dayCount;
    int findWorkerByName(vector<Worker*> list, const QString& s);
    int factoryLevel;
    double factoryUpgradeCost;

    void addFloor();

    GameScreen* gameScreen;
public slots:
    void comparingWorkers(const QString& s1, const QString& s2);
    void findFiredWorker(const QString& s);
    void hireNewEmps();
    void hiringOldEmps();
    void checkWorkerDetails(const QString& s);
    void firingWorker(const QString&s);
    void startDay();
    void setWage(double wage);
    void addNewHire(Worker* w);
    void addingOldWorker(const QString& s);
<<<<<<< HEAD

    void addWorkerToStation(int currentWS, string name);

=======
    void upgradeProduct(string name);
>>>>>>> e694275795f2b88fd369ca2ea63cb7a2f89fc905
    void upgradeFactory();

private slots:
    void endDay();

};

#endif // FACTORY_H
