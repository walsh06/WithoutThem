#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QWidget>
#include <vector>
#include "Worker.h"

namespace Ui {
class GameScreen;
}

class GameScreen : public QWidget
{
    Q_OBJECT

public:
    explicit GameScreen(QWidget *parent = 0);
    ~GameScreen();
    void updateFactory(int dayCount, double money, int workerCount);
    void updateWorkers(std::vector<Worker*> workers);

signals:
   void updateWage(double wage);

private slots:
    void on_setWageBox_valueChanged(double arg1);

private:
    Ui::GameScreen *ui;
};

#endif // GAMESCREEN_H
