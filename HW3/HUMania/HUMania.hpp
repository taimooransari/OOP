#include <SDL.h>

void drawObjects(SDL_Renderer *gRnderer, SDL_Texture *assets);
void createObject(int x, int y);

struct Unit
{
    SDL_Rect srcRect, moverRect;
};

class Animal
{
public:
    Unit animals;
    int condition = 0;
    // Animal(Unit anm = NULL, int cond = 0)
    // {
    //     condition = cond;
    //     animals = anm;
    // };
};

class Animation
{
public:
    Unit animation1;
    Unit animation2;
    Unit animation3;
    // Animation(Unit a1 = NULL, Unit a2 = NULL, Unit a3 = NULL)
    // {
    //     animation1 = a1;
    //     animation2 = a2;
    //     animation3 = a3;
    // };
};