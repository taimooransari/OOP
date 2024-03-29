#pragma once
#include <SDL.h>
// #include "pigeon.hpp"
// #include "bee.hpp"
// #include "butterfly.hpp"
#include "objectCreator.hpp"
#include "unit.hpp"
#include <list>
using namespace std;

// Class HUMania
class HUMania
{
    // List of Unit*
    list<Unit *> animals;
    // ObjectCreator object to call it's function getObjects.
    ObjectCreator *o;

public:
    // draw the objects/units
    void drawObjects();
    // function that calls the objectCreator function
    void createObject(int, int);

    // create destructor which deletes all dynamic objects
    ~HUMania();
};
