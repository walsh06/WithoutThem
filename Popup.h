#ifndef POPUP_H
#define POPUP_H
#include "Worker.h"

#include <QDialog>
#include <QWidget>
#include <QListWidget>

namespace Ui {
class Popup;
}

class Popup : public QDialog
{
    Q_OBJECT

public:
    explicit Popup(QDialog *parent = 0);
    ~Popup();
    void addWorkers(vector<Worker*> nw, int num);

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

signals:
    void addNewWorker(Worker* w);

private:
    void populateCells(Worker* w, QListWidget *lWidget);
    void activateSlots(int num);
    Ui::Popup *ui;
    vector<QListWidget*> listWidgets;
    vector<Worker*> nw;
};

#endif // POPUP_H
