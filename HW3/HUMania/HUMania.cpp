#include <iostream>
#include "HUMania.hpp"
#include <vector>
using namespace std;

// Exact x,y,w,h values of animals as taken from http://www.spritecow.com/
Unit pigeon = {{7, 88, 155, 103}, {30, 40, 50, 50}};
Unit pigeon1 = {{0, 273, 153, 84}, {30, 40, 50, 50}};
Unit pigeon2 = {{2, 361, 159, 124}, {30, 40, 50, 50}};
Unit butterfly = {{257, 24, 173, 134}, {30, 40, 50, 50}};
Unit butterfly1 = {{257, 182, 192, 214}, {30, 40, 50, 50}};
Unit butterfly2 = {{248, 432, 248, 179}, {30, 40, 50, 50}};
Unit bee = {{527, 138, 194, 115}, {30, 40, 50, 50}};
Unit bee1 = {{527, 243, 194, 116}, {30, 40, 50, 50}};
Unit bee2 = {{540, 370, 193, 115}, {30, 40, 50, 50}};
// First rectangle is srcRect, second is moverRect
// these values are taken from the corresponding image in assets file
// use spritecow.com to find exact values of other asset images

vector<Animal> pigeons;
vector<Animal> butterflys;
vector<Animal> bees;
// create 2 more vectors for bees and butterflies

// movement of the birds/bees/butterflies along the x axis.
void Play_Animation(Animal &animals, Animation animations)
{
    switch (animals.condition)
    {
    case 0:
        /* code */
        animals.animals.srcRect = animations.animation1.srcRect; // Changes the animation of the animal on the same co-ordinates(wings up).
        animals.condition = 1;
        break;
    case 1:
        animals.animals.srcRect = animations.animation2.srcRect; // Changes the animation of the animal on the same co-ordinates(wings at centre).
        animals.condition = 2;
        break;

    case 2:
        animals.animals.srcRect = animations.animation3.srcRect; // Changes the animation of the animal on the same co-ordinates(wings at the bottom).
        animals.condition = 0;
        break;

    default:
        break;
    }

    animals.animals.moverRect.x = animals.animals.moverRect.x + 10; // increases the value x-cordinate to move the animal along the x-axis

    if (animals.animals.moverRect.x > 999)
    {                                        // if the animal reaches the maximum right of the GUI, the animal return from the left most side again.
        animals.animals.moverRect.x %= 1000;     // initializes the x-cordinate with 0 to return the animal to the left more corner.
        Play_Animation(animals, animations); // Recalls the animation function in order to continue the movement from extreme left to extreme right and continues on loop.
    }
}

// drawobject continues rendering the animals that are appearing on the screen. The while loop has been used to continue rendering each
// and every one of the animals that have been produced by the user by tapping on the screen on the specific co-ordinates.
void drawObject(SDL_Renderer *gRenderer, SDL_Texture *assets, vector<Animal> &animal, Animation animations)
{

    for (int i = 0; i < animal.size(); i++)
    {
        Play_Animation(animal[i], animations);
        SDL_RenderCopy(gRenderer, assets, &animal[i].animals.srcRect, &animal[i].animals.moverRect);
    }
}

// drawObjects calls the drawObject function to render the animals along with their animation based on their location
// with respect to the pointer and the while loop in drawObject.
void drawObjects(SDL_Renderer *gRenderer, SDL_Texture *assets)
{

    Animation pigeonAnimationstype = {pigeon, pigeon1, pigeon2};
    Animation beesAnimationstype = {bee, bee1, bee2};
    Animation butterfliesAnimationstype = {butterfly, butterfly1, butterfly2};

    drawObject(gRenderer, assets, pigeons, pigeonAnimationstype);
    drawObject(gRenderer, assets, bees, beesAnimationstype);
    drawObject(gRenderer, assets, butterflys, butterfliesAnimationstype);
}
// RandomAnimalSelection randomly selects an animal to be rendered between the values 1 to 3.
void RandomAnimalSelection()
{
    int range = 3;
    int value = rand() % (range + 1); // Random value generated between 0 to 3.

    Animal animals;
    animals.condition = 0; // Initially the animals are generated at the animationtype when their wings are up hence the condition is kept 0.

    if (value == 1)
    { // Generates pigeon when the random value is 1.
        animals.animals = pigeon;
        pigeons.push_back(animals); // Pushes back the generated at the back of a vector to make sure it stays on the screen until the user closes the window.
    }
    else if (value == 2)
    { // Generates bees when the random value is 2
        animals.animals = bee;
        bees.push_back(animals); // Pushes back the generated at the back of a vector to make sure it stays on the screen until the user closes the window.
    }
    else if (value == 3)
    { // Generates butterfly when the random value is 3
        animals.animals = butterfly;
        butterflys.push_back(animals); // Pushes back the generated at the back of a vector to make sure it stays on the screen until the user closes the window.
    }
}

// createObject initializes moverRect with new x and y values as the animal moves along the change in x and y co-ordinates as mentioned in Animation() function above.
void createObject(int x, int y)
{
    pigeon.moverRect = {x, y, 40, 40};
    butterfly.moverRect = {x, y, 40, 40};
    bee.moverRect = {x, y, 40, 40};
    RandomAnimalSelection();
    // TODO: create an object randomly, and push it into corresponding vector
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
}
