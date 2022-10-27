#include <iostream>
#include "HUMania.hpp"
#include <stdlib.h>

void HUMania::drawObjects()
{
    // call draw functions of all the objects here
    // p1.draw();
    // p1.fly(); // this function is called to move the pigeon

    for (int i = 0; i < pigeons.size(); i++)
    {
        pigeons[i]->draw();
        pigeons[i]->fly();
        pigeons[i]->animate();
    }
    for (int i = 0; i < butterflies.size(); i++)
    {
        butterflies[i]->draw();
        butterflies[i]->fly();
        butterflies[i]->animate();
    }
    for (int i = 0; i < bees.size(); i++)
    {
        bees[i]->draw();
        bees[i]->fly();
        bees[i]->animate();

        if (bees[i]->destroy())
        {
            delete bees[i];
            bees.erase(bees.begin() + i);

            cout << "destroyed2" << endl;
        }
    }
}

void HUMania::createObject(int x, int y)
{
    // std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
    int rnd = rand() % 3;
    cout << rnd << endl;
    if (rnd == 0)
    {
        Bee *b = new Bee(x, y);
        bees.push_back(b);
    }
    else if (rnd == 1)
    {
        Butterfly *b = new Butterfly(x, y);
        butterflies.push_back(b);
    }
    else
    {

        Pigeon *p = new Pigeon(x, y);
        pigeons.push_back(p);
    }
}
