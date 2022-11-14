#include "unit.hpp"
// Unit implementation will go here.

// in project implementation this draw function should only be in superclass
void Unit::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

// fly() is overrided from the superclass
void Unit::fly()
{
    //
    moverRect.x += 5;
}

Unit::Unit(SDL_Rect src, int x, int y, int st)
{
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = src;

    // it will display Unit on x = 30, y = 40 location, the size of Unit is 50 width, 60 height
    moverRect = {x, y, 50, 50};
    state = st;
}

SDL_Rect Unit::getSrc()
{
    return srcRect;
};
SDL_Rect Unit::getMover()
{
    return moverRect;
};

void Unit::setSrc(SDL_Rect s)
{
    srcRect = s;
};
void Unit::setMover(SDL_Rect m)
{
    moverRect = m;
};
void Unit::animate()
{
    switch (state)
    {
        // bee
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

        // pigreon

    case 3:
        state = 4;
        srcRect = {0, 273, 153, 84};
        break;

    case 4:
        state = 5;
        srcRect = {2, 361, 159, 124};
        break;

    case 5:
        state = 3;
        srcRect = {7, 88, 160, 103};
        break;
    // butterfly
    case 6:
        state = 7;
        srcRect = {257, 182, 192, 214};
        break;

    case 7:
        state = 8;
        srcRect = {248, 432, 248, 179};
        break;

    case 8:
        state = 6;
        srcRect = {257, 24, 173, 134};
        break;
    default:
        break;
    }
};
