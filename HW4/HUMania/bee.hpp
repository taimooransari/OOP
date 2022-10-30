#include <SDL.h>
#include "drawing.hpp"
class Bee
{

    SDL_Rect srcRect, moverRect;
    int state;
    // hover state
    bool isHovering = false;
    // Frames to hover count
    int frameHoverLeft = 10;

public:
    void draw();
    void fly();
    Bee();

    // you may add other overloaded constructors here...

    Bee(int x, int y);
    
    void animate();
    bool destroy();
    void hoverFrame();
    bool getHoverState();
};