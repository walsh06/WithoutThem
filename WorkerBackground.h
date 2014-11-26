#ifndef WORKERBACKGROUND_H
#define WORKERBACKGROUND_H

#include <string>

class WorkerBackground
{
public:
    WorkerBackground();
    int getNumChildren();
    int getAge();
    bool hasHusband();
    int getNumSiblings();
private:
    int numChildren;
    int age;
    int numSiblings;
    bool husband;

};

#endif // WORKERBACKGROUND_H
