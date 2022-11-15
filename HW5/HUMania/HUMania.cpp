#include <iostream>
#include <typeinfo>
#include "HUMania.hpp"
#include <stdlib.h>

// draw function that iterates through the vector and draws, flies and animates each animal.
void HUMania::drawObjects()
{
    // call draw functions of all the objects here

    for (list<Unit *>::iterator i = animals.begin(); i != animals.end(); i++)
    {
        Unit *animal = *i;
        animal->draw();
        animal->fly();
        animal->animate();
        // if animal type is bee, it is deleted when it crosses the screen from right.
        Unit &a = *animal;
        int check = strcmp(typeid(a).name(), "3Bee");
        if (check == 0)
        {
            if (animal->getMover().x > 1000)
            {
                // code to delete from vector
                delete animal;
                animals.erase(i);
            }
        }
    }
}

// creates new objects
void HUMania::createObject(int x, int y)
{
    Unit *u = o->getObject(x, y);
    animals.push_back(u);
}

// Deconstructor, memory being releasedƒ
HUMania::~HUMania()
{

    for (list<Unit *>::iterator i = animals.begin(); i != animals.end(); i++)
    {

        Unit *animal = *i;
        delete animal;
        animals.erase(i);
    }
}