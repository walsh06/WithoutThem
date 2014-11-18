#ifndef SKILLTYPEENUMS_H
#define SKILLTYPEENUMS_H

namespace skills
{
    enum skillsType {
        SEAMSTRESS = 0,
        MECHANIC,
        FARMER,
        BUILDER,
        CARPENTER,
        SIZE_OF_SKILLS
    };
    static const char* skillNames[SIZE_OF_SKILLS] = {
        "Seamstress", "Mechanic", "Farmer",
        "Builder", "Carpenter"
    };
}
#endif // SKILLTYPEENUMS_H
