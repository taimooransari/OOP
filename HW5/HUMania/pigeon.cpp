#include "pigeon.hpp"
// pigeon implementation will go here.

// in project implementation this draw function should only be in superclass

// fly() is overrided from the superclass
void Pigeon::fly()
{
    SDL_Rect mov = Unit::getMover();
    mov.x += 10;
    // If the pigeon crosses screen from right it reappears from left.
    if (mov.x > 1000)
    {
        mov.x = 0;
    }
    Unit::setMover(mov);
}

Pigeon::Pigeon(int x, int y) : Unit({7, 88, 160, 103}, x, y,3)
{
    // src coorinates from assets.png file, they have been found using spritecow.com
    // srcRect = {7,88,160,103};
    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    // moverRect = {x, y, 50, 50};
}
