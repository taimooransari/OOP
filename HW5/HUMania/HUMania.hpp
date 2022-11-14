#pragma once
#include <SDL.h>
#include "pigeon.hpp"
#include "bee.hpp"
#include "butterfly.hpp"
#include "unit.hpp"
#include <vector>
#include <list>
using namespace std;

class ObjectCreator
{
public:
    Unit *getObject(int, int);
};

class HUMania
{

    // Right now we're creating one pigeon, just for practice. for details follow the guidlines
    //  Pigeon p1;
    list <Unit *> animals;
    ObjectCreator *o;
    // Create your list here
public:
    void drawObjects();
    void createObject(int, int);

    // create destructor which deletes all dynamic objects
};
