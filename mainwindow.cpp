#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SkillTypeEnums.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    Product *product = new Product("Uniform", skills::BUILDER, 10, 6000,"Cotton");
    Factory *factory = new Factory(product);

}

MainWindow::~MainWindow()
{
    delete ui;
}
