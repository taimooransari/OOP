#pragma once
#include <SDL.h>
#include "drawing.hpp"
#include "unit.hpp"
class Pigeon : public Unit
{


public:
    // overridden fly function
    void fly();
    // default and overloaded constructors
    Pigeon();
    Pigeon(int, int);
};
