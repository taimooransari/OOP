#include <iostream>
using namespace std;

void longest_key(char *keysPressed, int *releaseTime, int size)
{
    // char cr;
    // int max_duration = 0;
    // int lastReleased = 0;

    // for (int i = 0; i < size; i++)
    // {
    //     char c = *(keysPressed + i);
    //     int duration = *(releaseTime + i) - lastReleased;
    //     lastReleased = *(releaseTime + i);
    //     if (duration >= max_duration)
    //     {
    //         cr = c;
    //         max_duration = duration;
    //     }
    // }

    cout << 'c';
}

int main()
{
    int n;
    cin >> n;
    char *keysPressed = new char[n];
    int *releaseTime = new int[n];

    for (int i = 0; i < n; i++)
    {

        cin >> *(keysPressed + i);
    }

    for (int j = 0; j < n; j++)
    {

        cin >> *(releaseTime + j);
    }

    longest_key(keysPressed, releaseTime, n);
    return 0;
}
