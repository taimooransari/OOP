#pragma once
#include <SDL.h>
#include "drawing.hpp"

//Class Unit 
class Unit
{
    SDL_Rect srcRect, moverRect;
    int state;

public:
    // add the fly function here as well.
    void draw();
    virtual void fly()=0;
    SDL_Rect getSrc();
    SDL_Rect getMover();
    void setSrc(SDL_Rect);
    void setMover(SDL_Rect);
    void animate();
    Unit();
    Unit(SDL_Rect, int, int, int);
};