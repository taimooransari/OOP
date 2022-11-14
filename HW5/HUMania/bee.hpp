#pragma once
#include <SDL.h>
#include "drawing.hpp"
#include "unit.hpp"

class Bee : public Unit
{
    // frame count when the bee is hovering
    int frames = 10;
    // boolean variable telling if the bee is hovering or flying
    bool isHovering = false;

public:
    //    overridden fly function
    void fly();
    //  default and overloaded constructor
    Bee();
    Bee(int, int);
};
