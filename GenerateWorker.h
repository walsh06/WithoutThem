#ifndef GENERATEWORKER_H
#define GENERATEWORKER_H
#include "Worker.h"

class GenerateWorker
{
public:
    GenerateWorker();
    Worker* generateWorker();
    string generateAttribute(string filename);
private:
};

#endif // GENERATEWORKER_H
