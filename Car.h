#ifndef CAR_H
#define CAR_H

#include "Product.h"
#include "SkillTypeEnums.h"

using namespace skills;

class Car: public Product
{
    public:
        Car(string name,skillsType skill, int cost,
            int timeCost, string materialType);

    private:

    protected:
};

#endif // CAR_H
