#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include "SkillTypeEnums.h"

using namespace std;

class Product
{
public:
    Product(string name, skills::skillsType skill, int materialCost,
            int timeCost, string materialNeeded, double value, double upgradeCost);

    string getName();
    skills::skillsType getSkillType();
    string getMaterialNeeded();
    int getMaterialCost();
    int getTimeCost();

    double getValue();

    double getUpgradeCost();

    void setUpgradeCost(double cost);


private:

    string name;
    skills::skillsType skill;
    string materialNeeded;
    int materialCost;
    int timeCost;
    double upgradeCost;
    double value;
    //TO DO:
    //          - Time cost should be standard
    //          - it could be 3 minutes but this would be with one worker, with stat 1/100
    //                  -2 workers = 1.5 minutes
    //                  -Better stats = quicker + less material cost
};

#endif // PRODUCT_H
