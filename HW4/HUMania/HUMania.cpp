#include <iostream>
#include "HUMania.hpp"



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
    }
}

void HUMania::createObject(int x, int y)
{
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
    Bee *p = new Bee(x,y);
    bees.push_back(p);

}
