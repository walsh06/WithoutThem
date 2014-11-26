#include "mainwindow.h"
#include "Factory.h"
#include "Product.h"
#include <QApplication>
#include "DatabaseManipulator.h"

#include <QCoreApplication>
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*DatabaseManipulator *db = new DatabaseManipulator();
    //
    db->getProduct("Uniform");
    db->getProductNames();
    db->upgradeProduct("Uniform");
    */

    return a.exec();

 }


