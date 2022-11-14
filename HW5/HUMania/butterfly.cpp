#include "butterfly.hpp"

// fly() is overrided from the superclass
void Butterfly::fly()
{
    SDL_Rect mov = Unit::getMover();
    mov.x += 15;
    mov.y += 9 * direction;
    // butterfly reappears from left when it passes screen from right.
    if (mov.x > 1000)
    {
        mov.x = 0;
    }
    // it shifts y-direction when reaches either the top or bottom opf the screen
    if (mov.y <= 0 || mov.y >= 550)
    {
        direction *= -1;
    }
    Unit::setMover(mov);
}

Butterfly::Butterfly(int x, int y) : Unit({257, 24, 173, 134}, x, y, 6)
{
    // src coorinates from assets.png file, they have been found using spritecow.com
    // srcRect = {7,88,160,103};
    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    // moverRect = {x, y, 50, 50};
}
