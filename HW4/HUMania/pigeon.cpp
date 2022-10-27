#include "pigeon.hpp"
// pigeon implementation will go here.

void Pigeon::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

void Pigeon::fly()
{
    // you have to do flying animations here
    moverRect.x += 5;
    if (moverRect.x >= 1000)
    {
        moverRect.x = 0;
    }
}

Pigeon::Pigeon(int x, int y)
{
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {7, 88, 160, 103};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {x, y, 50, 50};
    // initialize with state 0
    state = 0;
}
void Pigeon::animate()
{
    switch (state)
    {
    case 0:
        state = 1;
        srcRect = {0, 273, 153, 84};
        break;

    case 1:
        state = 2;
        srcRect = {2, 361, 159, 124};
        break;

    case 2:
        state = 0;
        srcRect = {7, 88, 160, 103};
        break;
    default:
        break;
    }
}