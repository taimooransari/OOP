#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include "unit.hpp"
class Butterfly: public Unit{

    // SDL_Rect srcRect, moverRect;
    int direction =1;
public:
    // add the fly function here as well.
    // void draw();
    void fly();
    Butterfly();
    Butterfly(int , int); 
    // may add other overloaded constructors here... 
};
