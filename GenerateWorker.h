#ifndef GENERATEWORKER_H
#define GENERATEWORKER_H
#include "Worker.h"

class GenerateWorker
{
public:
    GenerateWorker();
    Worker* getWorker();
    void generateWorker();
    string generateBackground();
private:
    string getFirstname();
    string getSurename();
    Worker* worker;
};

#endif // GENERATEWORKER_H