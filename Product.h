#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

class Product
{
public:
    Product(string name, string type, int materialCost, int timeCost);

    string getName();
    string getType();
    int getMaterialCost();
    int getTimeCost();

private:

    string name;
    string type;
    int materialCost;
    int timeCost;
    //TO DO:
    //          - Time cost should be standard
    //          - it could be 3 minutes but this would be with one worker, with stat 1/100
    //                  -2 workers = 1.5 minutes
    //                  -Better stats = quicker + less material cost
};

#endif // PRODUCT_H
