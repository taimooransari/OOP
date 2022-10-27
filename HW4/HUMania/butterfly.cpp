#include "butterfly.hpp"
// Butterfly implementation will go here.

void Butterfly::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

void Butterfly::fly()
{
    // you have to do flying animations here
    moverRect.x += 10;

    if (downwardsDirected)
    {

        moverRect.y += 6;
        if (moverRect.y > 550)
        {
            downwardsDirected = false;
        }
    }
    else
    {
        moverRect.y -= 6;
        if (moverRect.y <= 0)
        {
            downwardsDirected = true;
        }
    }

    if (moverRect.x >= 1000)
    {
        moverRect.x = 0;
    }
}

Butterfly::Butterfly(int x, int y)
{
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {257, 24, 173, 134};

    // it will display Butterfly on x = 30, y = 40 location, the size of Butterfly is 50 width, 60 height
    moverRect = {x, y, 50, 50};
    // initialize with state 0
    state = 0;
    // move down
    downwardsDirected = true;
}
void Butterfly::animate()
{
    switch (state)
    {
    case 0:
        state = 1;
        srcRect = {257, 182, 192, 214};
        break;

    case 1:
        state = 2;
        srcRect = {248, 432, 248, 179};
        break;

    case 2:
        state = 0;
        srcRect = {257, 24, 173, 134};
        break;
    default:
        break;
    }
}
