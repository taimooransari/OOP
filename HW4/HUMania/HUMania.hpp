#include <SDL.h>
#include "pigeon.hpp"
#include "bee.hpp"
#include "butterfly.hpp"
#include <vector>
#include <list>
using namespace std;

class HUMania
{
    // Vectors holding objects of type pigeon, bee, butterfly.
    vector<Pigeon *> pigeons;
    vector<Butterfly *> butterflies;
    vector<Bee *> bees;

public:
    ~HUMania();
    void drawObjects();
    void createObject(int, int);
};