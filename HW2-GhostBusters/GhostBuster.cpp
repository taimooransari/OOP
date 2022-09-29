#include "GhostBuster.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Currently rows and columns are set to 8, however your game implementation should work for any other number
const int rows = 8, cols = 8;

// grid will store characters matrix of rows*cols size, you have to allocate memory to it in initialize function below
char *grid = NULL;

// Ghost will be placed over this location
int ghostRow, ghostCol;

// *****************************************************************************************************
// No change zone: Don't change anything until the next stars line
// *****************************************************************************************************

// Don't Change it: Screen width and height values
const int width = 1000, height = 600;

// Don't Change: This function is dealing with SDL and currently it's complete. Don't change anything here
void drawOneBlock(SDL_Renderer *renderer, SDL_Texture *texture, int row, int col, char sym)
{
    int xbox = width / cols;
    int ybox = height / rows;
    SDL_Rect src;
    switch (sym)
    {
    case 'L':
        src = {141, 7, 104, 113};
        break;
    case 'S':
        src = {427, 12, 129, 103};
        break;
    case 'T':
        src = {268, 10, 130, 111};
        break;
    case 'B':
        src = {0, 3, 114, 111};
        break;
    case 'G':
        src = {571, 0, 123, 121};
        break;
    case 'Z':
        src = {571, 0, 25, 25};
        break;
    case 'F':
        src = {707, 16, 90, 86};
        break;
    }
    SDL_Rect mov = {xbox * col, ybox * row, xbox - 10, ybox - 10};
    SDL_RenderCopy(renderer, texture, &src, &mov);
}

void drawBlocks(SDL_Renderer *renderer, SDL_Texture *texture)
{
    // Call drawOneBlock for all of the blocks of grid
    // for example to draw a snake over block (3, 5) you call it this way:
    // drawOneBlock(renderer, texture, 3, 5, 'S');
    if (grid == NULL)
        return;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            drawOneBlock(renderer, texture, i, j, grid[i * cols + j]);
        }
    }
}

// *****************************************************************************************************
// No change zone ends here
// *****************************************************************************************************

// To Do zone:

bool ended = false;

void initialize()
{
    // Create memory for grid here, it should be one dimensional array.
    // The memory should be rows*cols size.
    // Initialize entire grid with 'L' so that locks are displayed all over
    grid = new char[rows * cols];
    fill_n(grid, rows * cols, 'L');
    // generate two random numbers and store in ghostRow and ghostCol variables

    ghostRow = rand() % rows;
    ghostCol = rand() % cols;
    cout << "ghost at " << ghostRow << "," << ghostCol << endl;
}

// Function returning the type of hint to display depending on the clicked row and column
char boxHint(int row, int col)
{
    char hint;
    int xDist = abs(col - ghostCol);
    int yDist = abs(row - ghostRow);
    char allHints[3] = {'S', 'T', 'B'};
    // if the row is same, only the column difference is calculated
    int dist = sqrt(pow(xDist, 2) + pow(yDist, 2));
    if (dist <= 1)
    {
        return allHints[0];
    }
    else if (dist <= 3)
    {
        return allHints[1];
    }
    else if (dist == 4)
    {
        return allHints[2];
    }
    else
    {
        return allHints[rand() % 3];
    }
}

void huntGhost(int x, int y)
{
    // this function is called every time you click on the screen
    // x, y are screen coordinates, you need to identify the block from these coordinates and using screen width and height values
    // each block size is width/cols x height/rows
    // according to game rules you need to put appropriate character in the grid for that block
    // Place 'S' to draw a snake
    // place 'T' to draw a turtle
    // place 'B' to draw a bunny
    if (!ended)
    {
        int clickedCol = x / (width / cols), clickedRow = y / (height / rows);
        int gridBox = clickedCol + clickedRow * rows;
        if(*(grid + gridBox)!='L'){
            return;
        }
        *(grid + gridBox) = boxHint(clickedRow, clickedCol);
    }
}

void bustGhost(int x, int y)
{
    // this function is called when you right-click
    // it should work only one time, and you decide whether game is won or failed
    // once the game is won/failed, nothing in game should change anymore.
    // according to game rules you need to put appropriate character in the grid for that block
    // place 'S' to draw snake, when the game is won
    // place 'F' to draw failed symbol, when the game is failed
    if (!ended)
    {
        int clickedCol = x / (width / cols), clickedRow = y / (height / rows);
        int gridBox = clickedCol + clickedRow * rows;
        if (clickedCol == ghostCol && clickedRow == ghostRow)
        {
            *(grid + gridBox) = 'G';
            cout<<"Ghost busted at: "<<clickedRow<<", "<<clickedCol<<endl;
        }
        else
        {
            *(grid + gridBox) = 'F';
            cout<<"Game lost at: "<<clickedRow<<", "<<clickedCol<<endl;
        }
        ended = true;
    }
    else
    {
        quitGhostBuster();
    }
}

void quitGhostBuster()
{
    // delete the grid here

    delete[] grid;
    grid = NULL;
}