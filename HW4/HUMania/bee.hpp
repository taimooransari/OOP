#include <SDL.h>
#include "drawing.hpp"
class Bee
{

    SDL_Rect srcRect, moverRect;
    int state;

public:
    void draw();
    void fly();
    Bee();

    // you may add other overloaded constructors here...

    Bee(int x, int y);

    void animate();
    bool destroy();
};