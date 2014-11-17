#include "Factory.h"

Factory::Factory(Product *product)
{
    this->product = product;
    this->productCount = 0;
    this->calcStats();
    this->makeProduct();
}

StatsList Factory::getStats()
{
    return this->stats;
}

void Factory::calcStats()
{
    for (auto &worker : workers) // access by reference to avoid copying
    {
        this->stats = this->stats + worker.getStats();
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

    cout << productCount << endl;
    //Creates product every 1/6th of a second
    QTimer::singleShot(1000, this, SLOT(addProduct()));

}

void Factory::addProduct()
{
    //add 1 to product
    productCount++;
    //TO DO: Factor in materials etc.

    //call makeProduct again
    makeProduct();
}
