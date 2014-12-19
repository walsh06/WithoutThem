#ifndef SKILLTYPEENUMS_H
#define SKILLTYPEENUMS_H

namespace skills
{
    enum skillsType {
        NONE = 0,
        SEAMSTRESS ,
        MECHANIC,
        FARMER,
        BUILDER,
        CARPENTER,
        SIZE_OF_SKILLS
    };
    static const char* skillNames[SIZE_OF_SKILLS] = {
        "None", "Seamstress", "Mechanic", "Farmer",
        "Builder", "Carpenter"
    };
}
#endif // SKILLTYPEENUMS_H
