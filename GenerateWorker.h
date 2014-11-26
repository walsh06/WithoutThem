#ifndef GENERATEWORKER_H
#define GENERATEWORKER_H
#include "Worker.h"

class GenerateWorker
{
public:
    GenerateWorker();
    Worker* getWorker();
    void generateWorker();
    string generateAttribute(string filename);
private:
    Worker* worker;
};

#endif // GENERATEWORKER_H
