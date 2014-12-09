#ifndef REHIREWINDOW_H
#define REHIREWINDOW_H

#include <QDialog>
#include <vector>
#include "Worker.h"
#include "StatsList.h"
#include "WorkerBackground.h"

using namespace std;
namespace Ui {
class ReHireWindow;
}

class ReHireWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ReHireWindow(QWidget *parent = 0);
    ~ReHireWindow();
    void updateFiredWorkers(vector<Worker *> firedWorkers);
    void updateDetailsView(Worker* w);
    void updateEmployees(map<string, Worker *> emps);
    void updateComparedWorkersWindow(QString s);
signals:
    void checkFiredWorkerDetails(const QString& s);
    void rehiring(const QString& s);
    void compareWorkers(const QString& s1, const QString& s2);

private slots:
    void on_rehireButton_clicked();

    void on_compareWorkers_clicked();

    void on_workerDetailsButton_clicked();

private:

    vector<Worker*> firedWorkers;
    void displayWorker(Worker* w);

private:
    Ui::ReHireWindow *ui;
};

#endif // REHIREWINDOW_H
