#include "objectCreator.hpp"
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