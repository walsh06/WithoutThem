#ifndef FACTORY_H
#define FACTORY_H

#include <vector>
#include "Worker.h"
#include "StatsList.h"
#include "Product.h"
#include <QTimer>
#include <iostream>
#include <QtCore/QObject>

using namespace std;
class Factory : public QObject
{
    Q_OBJECT

public:
    Factory(Product *product); //TO DO find out why this won't work as not pointer

    StatsList getStats();
    void calcStats();
    Product* getProduct();
    void setProduct(Product* product);

private:
    //TO DO:
    //Add Current Product
    //Extra:
    //multiple products/product list
    Product *product;


    //TO DO:
    //Add Worker List
    vector<Worker> workers;
    StatsList stats;
    int productCount;

public slots:
    void makeProduct();

    void addProduct();

private slots:







    //TO DO:
    //Add Factory Stats
    //Factory stats are the sumation of worker stats

};

#endif // FACTORY_H
