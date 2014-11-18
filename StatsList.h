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
    int getFarmingSkill();
    int getCarpentrySkill();
    int getBuildingSkill();

    void setTextileSkill(int n);
    void setMachinerySkill(int n);

    StatsList operator+(const StatsList& stats);
    //add more stats

private:
     int machinery;
     int textile;
     int building;
     int carpentry;
     int farming;
};

#endif // STATSLIST_H
