#include "bee.hpp"
#include <stdlib.h>
// Bee implementation will go here.

// fly() is overrided from the superclass
void Bee::fly()
{
    // condition block checking if the bee is hovering or flying
    if (isHovering)
    {
        frames--;
        if (frames <= 0)
        {
            isHovering = false;
            frames = 10;
        }
    }
    else
    {
        SDL_Rect mov = Unit::getMover();
        mov.x += 12;
        Unit::setMover(mov);

        int rnd = rand() % 100;
        if (rnd < 5)
        {
            isHovering = true;
        }
    }
}

Bee::Bee(int x, int y) : Unit({63, 619, 151, 166}, x, y, 0)
{
    // src coorinates from assets.png file, they have been found using spritecow.com
    // srcRect = {7,88,160,103};
    // it will display Bee on x = 30, y = 40 location, the size of Bee is 50 width, 60 height
    // moverRect = {x, y, 50, 50};
}
