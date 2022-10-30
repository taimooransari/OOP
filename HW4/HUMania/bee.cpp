#include "bee.hpp"
// Bee implementation will go here.
#include <iostream>
using namespace std;
void Bee::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

void Bee::fly()
{
    // you have to do flying animations here

    // Integer that determines where the bee will hover or fly.
    int check = rand() % 100;
    // 5% probability of hover state activating. Else the bee just moves/flys.
    if (check < 5)
    {
        isHovering = true;
        frameHoverLeft = 10;
    }
    else
    {
        moverRect.x += 10;
    }
}

// Function controlling the hover frames count.
//  Since the bee hovers for 10 frames, this manages updating the frame count and changing hover to fly state after 10 frames.
void Bee::hoverFrame()
{
    if (frameHoverLeft < 1)
    {
        isHovering = false;
    }
    else
    {
        frameHoverLeft -= 1;
    }
}

// Getter Function to get the boolean value of hovering state of the bee.
bool Bee::getHoverState()
{
    return isHovering;
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

    // animation state with up, down and midway wings of bee.
    // chnging srcRect of each state depending on the current state.
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

// This function returns true if the bee has moved past the screen from the right side.
//  This boolean return value serves as a condition to determine wheteher we delete this bee from rendering or not.
bool Bee::destroy()
{
    return moverRect.x >= 1000;
}
