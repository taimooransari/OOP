#include <iostream>
#include <cstdlib>
using namespace std;
int **create2Darray(int row, int col);
void populate2Darray(int **arr, int r, int c);
void print2Darray(int **a, int rr, int cc);
void releaseMemory(int **w, int rr);

int **create2Darray(int row, int col)
{
  int **p = new int *[row];
  for (int i = 0; i < row; i++)
  {
    *(p + i) = new int[col];
  }
  return p;
}
void populate2Darray(int **arr, int r, int c)
{
  for (int i = 0; i < r; i++)
  {

    for (int j = 0; j < c; j++)
    {

      *(*(arr + i) + j) = rand();
    }
  }
}

void print2Darray(int **a, int rr, int cc)
{
  for (int i = 0; i < rr; i++)
  {

    for (int j = 0; j < cc; j++)
    {

      cout << *(*(a + i) + j) << " ";
    }
    cout << endl;
  }
}

void releaseMemory(int **w, int rr)
{
  for (int i = 0; i < rr; i++)
  {
    delete[] * (w + i);
  }
  delete[] w;
}

int main()
{
  // 2D array - Dynamic memory allocation
  //=====================================

  // p is a pointer of 2D array - dimensions 4X5
  int **p = create2Darray(4, 5);
  populate2Darray(p, 4, 5); // it will populate the 2Darray with random integers
  print2Darray(p, 4, 5);    // outputs the 2Darray to screen
  releaseMemory(p, 4);      // releasing the memory created dynamically
  // system("pause");
}