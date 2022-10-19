// q1

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
// 1-- Create a class Node, which has one variable for storing data and a pointer which points to the next node

class Node
{
public:
    int value;
    Node *next;
    // Node(){}
    Node(int val, Node *ptr = NULL)
    {
        value = val;
        next = ptr;
    }
};

// 2 -- Create a class Queue ; which has two public pointers for front and rear nodes
//     and it also has two public functions void Enqueue(int x) and int Dequeue()
//      also add a function print_queue() which prints all the elements in the queue

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void Enqueue(int x)
    {
        Node *newRear = new Node(x);

        if (front == NULL)
        {
            front = new Node(x);
            rear = newRear;
            front->next = rear;
            return;
        }

        rear->next = newRear;
        rear = newRear;
    }

    int Dequeue()
    {
        int val = front->value;
        if (front == rear)
        {
            rear = NULL;
            front = NULL;
            return val;
        }
        else
        {
            front = front->next;
            return val;
        }
    }
    void print_queue()
    {
        Node *tmp = front;
        while (tmp != rear)
        {
            cout << tmp->next->value << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

int main()
{

    Queue *queue = new Queue; //

    int n, value; // n is the number of values to be enqueued

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> value; // reading the value
        queue->Enqueue(value);
    }

    queue->print_queue(); // prints the queue after enqueuing the data

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        queue->Dequeue();
    }

    queue->print_queue(); // prints the queue after enqueuing the data

    return 0;
}

// q2

#include <iostream>

using namespace std;
class Time
{
public:
    int hour;
    int min;
    int sec;
    Time()
    {
        hour = 0;
        min = 0;
        sec = 0;
    }
    Time(int h, int m, int s)
    {
        hour = h;
        min = m;
        sec = s;
    }
    void show()
    {
        adjust();
        if (hour < 10)
        {
            cout << 0;
        }
        cout << hour << ":";
        if (min < 10)
        {
            cout << 0;
        }
        cout << min << ":";
        if (sec < 10)
        {
            cout << 0;
        }
        cout << sec << endl;
    }

    void adjust()
    {
        if (sec >= 60)
        {
            min += sec / 60;
            sec = sec % 60;
        }
        if (min >= 60)
        {
            hour += min / 60;
            min = min % 60;
        }
        if (hour >= 24)
        {
            hour = hour % 24;
        }
    }
    Time operator+(Time objT)
    {
        return Time(hour + objT.hour, min + objT.min, sec + objT.sec);
    }
};

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int hh, mm, ss;
    cin >> hh >> mm >> ss;
    Time t1(hh, mm, ss); // t1(hh, mm, ss)
    cin >> hh >> mm >> ss;
    Time t2(hh, mm, ss);
    Time t3;
    t3 = t1 + t2; // adding two times should produce a valid time, overflowed hours/minutes/seconds should be adjusted.
    // e.g. adding 18:10:20 with 10:20:30 results in 4:30:50

    t1.show();
    t2.show();
    t3.show();
    return 0;
}

// q3

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 1-- Create a class Node, which has one variable for storing data and a pointer which points to the next node

class Node
{
public:
    int value;
    Node *next;
    // Node(){}
    Node(int val, Node *ptr = NULL)
    {
        value = val;
        next = ptr;
    }
};

// 2 -- Create a class Queue ; which has two public pointers for front and rear nodes
//     and it also has two public functions void Enqueue(int x) and int Dequeue()
//      also add a function print_queue() which prints all the elements in the queue

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void Enqueue(int x)
    {
        Node *newRear = new Node(x);

        if (front == NULL)
        {
            front = newRear;
            rear = newRear;
        }
        else
        {
            rear->next = newRear;
            rear = newRear;
        }
    }

    int Dequeue()
    {
        int val;
        if (front != NULL)
        {

            val = front->value;
            Node *tmp = front;
            front = tmp->next;
            delete[] tmp;
        }

        return val;
    }
    void print_queue()
    {
        Node *tmp = front;

        while (tmp != NULL)
        {
            cout << tmp->value << " ";
            tmp = tmp->next;
            if (tmp == NULL)
            {
                cout << endl;
            }
        }
    }
};

int main()
{

    Queue *queue = new Queue; //

    int n, value; // n is the number of values to be enqueued

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> value; // reading the value
        queue->Enqueue(value);
    }

    queue->print_queue(); // prints the queue after enqueuing the data

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        queue->Dequeue();
    }

    queue->print_queue(); // prints the queue after enqueuing the data

    return 0;
}