#pragma once
#include <SDL.h>
#include "drawing.hpp"
#include "unit.hpp"
class Pigeon : public Unit
{

    // SDL_Rect srcRect, moverRect;


public:
    // add the fly function here as well.
    // void draw();
    void fly();
    Pigeon();
    Pigeon(int, int);
    // may add other overloaded constructors here...
};
