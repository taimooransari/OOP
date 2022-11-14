#pragma once
#include <SDL.h>
#include "drawing.hpp"
#include "unit.hpp"
class Bee : public Unit
{
    int frames = 10;
    bool isHovering = false;

public:
    // add the fly function here as well.
    // void draw();
    void fly();
    Bee();
    Bee(int, int);
    // may add other overloaded constructors here...
};
