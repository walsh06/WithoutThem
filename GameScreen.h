#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QWidget>
#include <QGridLayout>
#include <QMessageBox>

#include <iostream>
#include <functional>

#include <QPushButton>

#include <WorkStation.h>
#include <vector>

#include "Worker.h"


using namespace std;
namespace Ui {
class GameScreen;
}

class GameScreen : public QWidget
{
    Q_OBJECT

public:
    explicit GameScreen(QWidget *parent = 0);
    ~GameScreen();
    void updateMoney(double money);
    void setStations(vector<WorkStation*> &stations);
    void displayWorkerDetails(Worker* w);
    void endDayPopup(double wages, double gross, double money);
    void eventPopup(string event);
    void displayUpgrade(bool success, int level, double money, double upgradeCost);

    void setUpgradeCost(double cost);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void updateWSView();

    void updateCurrentWS(int num);



public slots:
    void updateFactory(int dayCount, double money, int workerCount);
    void updateWorkers(std::map<string, Worker*> workers);
    void updateProductList(vector<string> list);

    void updateTimer();

signals:
   void updateWage(double wage);
   void hireEmps();
   void rehireOldEmps();
   void checkExistingWorkerDetails(const QString& s);
   void fireWorker(const QString& s);
   void factoryUpgrade();

private slots:
    void on_setWageBox_valueChanged(double arg1);

    void on_manufactureButton_clicked();

    void on_hireButton_clicked();

    void on_generateWorker_clicked();

    void on_workerDetailsButton_clicked();

    void on_fireWorker_clicked();

    void on_rehireWorkerButton_clicked();

    void on_upgradeFactory_clicked();

private:
    Ui::GameScreen *ui;
    QButtonGroup* wsButtons;
    void initWSButtons();
    int currentWS = 0;

    vector<WorkStation*> stations;

    int money, wages, gross, income;
};

#endif // GAMESCREEN_H
