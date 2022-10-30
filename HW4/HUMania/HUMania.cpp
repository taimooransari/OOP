#include <iostream>
#include "HUMania.hpp"
#include <stdlib.h>

// Function thats drawing/flying/animating the objects from the vectors.
void HUMania::drawObjects()
{

    // Looping through pigeons and calling its functions responsible for drawing, flying and animating it.

    for (int i = 0; i < pigeons.size(); i++)
    {
        pigeons[i]->draw();
        pigeons[i]->fly();
        pigeons[i]->animate();
    }

    // Looping through butterflies and calling its functions responsible for drawing, flying and animating it.
    for (int i = 0; i < butterflies.size(); i++)
    {
        butterflies[i]->draw();
        butterflies[i]->fly();
        butterflies[i]->animate();
    }

    // Looping through bee and calling its functions responsible for drawing, flying, hovering, animating and deleting it.
    for (int i = 0; i < bees.size(); i++)
    {
        bees[i]->draw();
        // Bee state determines if it's to be hovered or it flys.
        if (bees[i]->getHoverState())
        {
            bees[i]->hoverFrame();
        }
        else
        {
            bees[i]->fly();
        }

        bees[i]->animate();
        // The is destroyed if it moves past the screen from right.
        if (bees[i]->destroy())
        {
            delete bees[i];
            bees.erase(bees.begin() + i);
        }
    }
}

// Function that randomly decided which type of object is to be created when the screen is clicked.
void HUMania::createObject(int x, int y)
{
    int rnd = rand() % 3;
    // A new bee is dynamically created and pushed in the vector.
    if (rnd == 0)
    {
        Bee *b = new Bee(x, y);
        bees.push_back(b);
    }
    // A new butterfly is dynamically created and pushed in the vector.
    else if (rnd == 1)
    {
        Butterfly *b = new Butterfly(x, y);
        butterflies.push_back(b);
    }

    // A new pigeon is dynamically created and pushed in the vector.
    else
    {
        Pigeon *p = new Pigeon(x, y);
        pigeons.push_back(p);
    }
}

// Game destructor that releases all the dynamically allocated memory for each objects vector.
HUMania::~HUMania()
{
    for (int i = 0; i < pigeons.size(); i++)
    {
        delete pigeons[i];
    }

    for (int i = 0; i < bees.size(); i++)
    {
        delete bees[i];
    }

    for (int i = 0; i < butterflies.size(); i++)
    {
        delete butterflies[i];
    }
}