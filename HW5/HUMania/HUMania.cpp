#include <iostream>
#include <typeinfo>
#include "HUMania.hpp"
#include <stdlib.h>

// draw function that iterates through the vector and draws, flies and animates each animal.
void HUMania::drawObjects()
{
    // call draw functions of all the objects here

    // for (int i = 0; i < animals.size(); i++)
    // {
    //     animal->draw();
    //     animal->fly();
    //     animal->animate();
    //     // if animal type is bee, it is deleted when it crosses the screen from right.
    //     Unit &a = *animal;
    //     int check = strcmp(typeid(a).name(), "3Bee");
    //     if (check == 0)
    //     {
    //         if (animal->getMover().x > 1000)
    //         {
    //             // code to delete from vector
    //             delete animal;
    //             animals.erase(animals.begin() + i);
    //         }
    //     }
    // }
    for (list<Unit *>::iterator i = animals.begin(); i != animals.end(); i++)

    // for (Unit *animal : animals)
    {
        Unit *animal = *i;
        // cout << animal << endl;
        // cout << "----" << endl;
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

    int rnd = rand() % 3;
    // int rnd = 1;
    // Unit *u;
    if (rnd == 0)
    {
        Unit *u = new Pigeon(x, y);
        cout << "p ---->" << u << endl;
        return u;
    }
    else if (rnd == 1)
    {
        Unit *u = new Bee(x, y);
        cout << "p ---->" << u << endl;
        return u;
    }
    else
    {
        Unit *u = new Butterfly(x, y);
        cout << "p ---->" << u << endl;
        return u;
    }
}

// creates new objects
void HUMania::createObject(int x, int y)
{
    Unit *u = o->getObject(x, y);
    animals.push_back(u);
}
