#ifndef PRINTER_H
#define PRINTER_H

#include <string>
#include <iostream>

using namespace std;

class Printer
{
public:
    Printer();

    static void printEvent(string description);
};

#endif // PRINTER_H
