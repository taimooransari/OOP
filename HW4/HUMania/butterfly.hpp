#include <SDL.h>
#include "drawing.hpp"
class Butterfly
{

    SDL_Rect srcRect, moverRect;
    int state;
    bool downwardsDirected;

public:
    void draw();
    void fly();
    Butterfly();

    // you may add other overloaded constructors here...

    Butterfly(int x, int y);

    void animate();
};