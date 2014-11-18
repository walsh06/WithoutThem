#include "Car.h"
#include "Product.h"

#include  "SkillTypeEnums.h"

using namespace skills;

Car::Car(string name,skillsType skill, int cost,
         int timeCost, string materialNeeded):
    Product(name,skill, cost, timeCost, materialNeeded)
{

}
