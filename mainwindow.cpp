#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);


    Product *product = new Product("Uniform", "Textile", 10, 6000, 15);
    Factory *factory = new Factory();




}

MainWindow::~MainWindow()
{
    delete ui;
}
