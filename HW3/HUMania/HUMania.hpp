#include <SDL.h>

void drawObjects(SDL_Renderer *gRnderer, SDL_Texture *assets);
void createObject(int x, int y);

struct Unit
{
    SDL_Rect srcRect, moverRect;
};

// ANIMAL CLASS DEFINITION
class Animal
{
public:
    Unit animals;
    int state = 0;
};
//ANIMATION CLASS TO CHANGE STATE OF EACH ANIMAL
class Animation
{
public:
    Unit animation1;
    Unit animation2;
    Unit animation3;
};