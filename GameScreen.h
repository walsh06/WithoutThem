#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QWidget>
#include <QGridLayout>

#include <iostream>
#include <functional>

#include <QPushButton>

#include <WorkStation.h>
#include <vector>

#include "Worker.h"
#include "DatabaseManipulator.h"


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

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void updateWSView();

    void updateCurrentWS(int num);


    void updateTimer();

public slots:
    void updateFactory(int dayCount, double money, int workerCount);
    void updateWorkers(std::vector<Worker*> workers);

signals:
   void updateWage(double wage);

private slots:
    void on_setWageBox_valueChanged(double arg1);

private:
    Ui::GameScreen *ui;
    QButtonGroup* wsButtons;
    void initWSButtons();
    DatabaseManipulator *db;
    int currentWS = 0;

    vector<WorkStation*> stations;

};

#endif // GAMESCREEN_H
