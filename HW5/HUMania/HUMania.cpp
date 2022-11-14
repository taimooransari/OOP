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

// get object function that randomly returns one of the pigeon, bee, butterfly
Unit *ObjectCreator::getObject(int x, int y)
{
    // randomly get an integer 0, 1, 2 and create and return an animal.
    int rnd = rand() % 3;

    if (rnd == 0)
    {
        Unit *u = new Pigeon(x, y);
        return u;
    }
    else if (rnd == 1)
    {
        Unit *u = new Bee(x, y);
        return u;
    }
    else
    {
        Unit *u = new Butterfly(x, y);
        return u;
    }
}

// creates new objects
void HUMania::createObject(int x, int y)
{
    Unit *u = o->getObject(x, y);
    animals.push_back(u);
}
