#include "bee.hpp"
// Bee implementation will go here.

void Bee::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

void Bee::fly()
{
    // you have to do flying animations here
    moverRect.x += 5;
    if (moverRect.x >= 1000)
    {
        moverRect.x = 0;
    }
}

Bee::Bee(int x, int y)
{
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {63, 619, 151, 166};

    // it will display Bee on x = 30, y = 40 location, the size of Bee is 50 width, 60 height
    moverRect = {x, y, 50, 50};
    // initialize with state 0
    state = 0;
}
void Bee::animate()
{
    switch (state)
    {
    case 0:
        state = 1;
        srcRect = {234, 630, 163, 162};
        break;

    case 1:
        state = 2;
        srcRect = {409, 650, 171, 147};
        break;

    case 2:
        state = 0;
        srcRect = {63, 619, 151, 166};
        break;
    default:
        break;
    }
}


