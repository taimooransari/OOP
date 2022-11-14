#pragma once
#include <SDL.h>
#include "drawing.hpp"
#include "unit.hpp"
class Butterfly : public Unit
{
    // direction determines if it moves downwards or upwards
    int direction = 1;

public:
    // overridden fly function
    void fly();
    // default and overloaded constructors
    Butterfly();
    Butterfly(int, int);
};
