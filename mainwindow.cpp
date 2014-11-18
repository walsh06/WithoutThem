#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SkillTypeEnums.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    Product *product = new Product("Uniform", skills::BUILDER, 10, 6000,"Cotton");
    Factory factory(product);


    factory.calcStats();
    factory.addProduct();



}

MainWindow::~MainWindow()
{
    delete ui;
}
