#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include "GenerateWorker.h"
#include "WorkerBackground.h"
#include "Worker.h"
#include "StatsList.h"
#include "SkillTypeEnums.h"

using namespace std;
using namespace skills;

/**Helper class to generate between 2 and 4 random workers*/
namespace generateW
{
    Worker* generateWorker()
    {
        int random = 0;
        string name;

        name = generateAttribute("firstname");
        name = name + generateAttribute("surename");
        Worker *worker = new Worker(name);
        WorkerBackground gb;
        worker->setBackground(gb);
        worker->setMoral(rand() % 4);

        double wage = (rand() % (19-7))+7;
        wage = wage / 7.00;
        double scale = 0.01;
        wage = floor(wage/scale + 0.5) * scale;

        worker->setWagePerDay(wage);

        StatsList stats = worker->getStats();
        random = rand() % skillsType::SIZE_OF_SKILLS;
        enum skillsType lookingFor = (skillsType)random;

        int skill1 = rand() % 4;
        int skill2 = rand() % 3;
        if(skillsType::SEAMSTRESS == lookingFor){
            stats.setTextileSkill(skill1);
            stats.setMachinerySkill(skill2);
        }else if(skillsType::CARPENTER == lookingFor){
            stats.setCarpentrySkill(skill1);
            stats.setBuildingSkill(skill2);
        }else if(skillsType::FARMER == lookingFor){
            stats.setFarmingSkill(skill1);
            stats.setMachinerySkill(skill2);
        }else if(skillsType::BUILDER == lookingFor){
            stats.setBuildingSkill(skill1);
            stats.setMachinerySkill(skill2);
        }else{
            stats.setMachinerySkill(skill1);
            stats.setBuildingSkill(skill2);
        }
        worker->setStatsList(stats);
        return worker;
    }

    /**Reads for the 'filename' and selects a random string from the file to return*/
    string generateAttribute(string filename)
    {
        ifstream readFile;
        int pos;
        int i = 0;
        string name, line;

        i = 0;
        filename = "../WithoutThem/"+ filename + ".txt";
        readFile.open(filename);
        if (readFile.good())
          {
            getline(readFile, name);
          }
        int count = atoi(name.c_str());
        pos = (rand() % count) + 1;
        if(readFile.is_open() ){
            while(getline (readFile,line)){
                if( i == pos){
                    name = line;
                    break;
                }
                i++;
            }
            name  = line;
        }
        readFile.close();

        if (readFile.is_open()){
            readFile.close();
        }
        return name;
    }
}
