#pragma once
#include <iostream>
using namespace std;

class Truck
{
public:
    string driver;
    double petrol;
    string regNo;
    int fullMileage;
    int emptyMileage;

    // def constructor
    Truck()
    {
        regNo = "nullptr";
        // driver = nullptr;
        // petrol = NULL;
        // regNo = nullptr;
        // fullMileage = NULL;
        // emptyMileage = NULL;
    }
    // overloaded concs
    Truck(string drvr, double ptrl, string reg, int full, int empty)
    {
        driver = drvr;
        petrol = ptrl;
        regNo = reg;
        fullMileage = full;
        emptyMileage = empty;
    }
};
