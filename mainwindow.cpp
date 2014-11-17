#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    Product *product = new Product("Uniform", "Textile", 10, 6000);
    Factory factory(product);


    factory.calcStats();
    factory.addProduct();



}

MainWindow::~MainWindow()
{
    delete ui;
}
