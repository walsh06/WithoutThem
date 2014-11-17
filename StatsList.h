#ifndef STATSLIST_H
#define STATSLIST_H

#include <map>
#include <string>


using namespace std;

class StatsList
{
public:
    StatsList();

    int getTextileSkill();
    int getMachinerySkill();
    StatsList operator+(const StatsList& stats);
    //add more stats

private:
     int machinery;
     int textile;
};

#endif // STATSLIST_H
