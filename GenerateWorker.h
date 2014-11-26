#ifndef GENERATEWORKER_H
#define GENERATEWORKER_H
#include "Worker.h"

class GenerateWorker
{
public:
    GenerateWorker();
    Worker* getWorker();
    void generateWorker();
private:
    string getFirstname();
    string getSurename();
    Worker* worker;
};

#endif // GENERATEWORKER_H
