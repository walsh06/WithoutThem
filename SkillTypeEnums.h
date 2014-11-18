#ifndef SKILLTYPEENUMS_H
#define SKILLTYPEENUMS_H

namespace skills
{
    enum skillsType {
        SEAMSTRESS = 0,
        MECHANIC = 1,
        ENGINEER = 2,
        FARMER = 3,
        BUILDER = 4,
        CARPENTER = 5,
        SIZE_OF_SKILLS
    };
    static const char* skillNames[SIZE_OF_SKILLS] = {
        "Seamstress", "Mechanic", "Engineer", "Farmer",
        "Builder", "Carpenter"
    };
}
#endif // SKILLTYPEENUMS_H
