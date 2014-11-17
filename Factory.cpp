#include "Factory.h"

Factory::Factory(Product *product)
{
    this->product = product;
    this->productCount = 0;
    this->money = 10;
}

StatsList Factory::getStats()
{
    return this->stats;
}

void Factory::calcStats()
{
    for (auto &worker : workers) // access by reference to avoid copying
    {
        this->stats = this->stats + worker->getStats();
    }
}

Product* Factory::getProduct()
{
    return this->product;
}

void Factory::setProduct(Product* product)
{
   this->product = product;
}

void Factory::makeProduct()
{





}

void Factory::addProduct()
{


    cout << "START" << endl;

    QTimer::singleShot(6000, this, SLOT(addProduct()));
    cout << "AFTER" << endl;
    productCount++;
    cout << productCount << endl;
}
