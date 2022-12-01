#include <iostream>
using namespace std;

template <typename D>
class MyQueue
{
public:
    int size, front, rear;
    D *arr;
    MyQueue(int s)
    {
        size = s;
        front = -1;
        rear = -1;
        arr = new D[size];
        for (int i = 0; i < size; i++)
            cin >> arr[i];
    }
    void show()
    {
        if (front != -1)
        {
            for (int i = 0; i < rear + 1; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
        else
        {
            cout << "Queue is empty" << endl;
        }
    }
    // Implement Enqueue function.

    void enqueue(D val)
    {
        if (front == -1)
        {
            arr[0] = val;
            front = 0;
            rear = 0;
        }
        else
        {
            if (rear < size - 1)
            {
                arr[rear + 1] = val;
                rear++;
            }
            else
            {
                cout << "No space in queue" << endl;
            }
        }
    }
    // Implemen Dequeue function.
    D dequeue()
    {
        D temp;
        if (front == -1)
        {
            cout << "Queue Empty" << endl;
            return temp;
        }
        else if (rear == 0)
        {
            int tmp = front;
            front--;
            rear--;
            return arr[tmp];
        }
        else
        {
            D val = arr[front];

            for (int i = 0; i < rear; i++)
            {
                arr[i] = arr[i + 1];
            }
            rear--;
            return val;
        }
    }
    // Implement front function.

    D showFront()
    {
        D tmp;
        if (front != -1)
        {
            return arr[front];
        }
        else
        {
            return tmp;
        }
    }
    // Implement is_empty function.
    bool is_empty()
    {
        return front == -1;
    }
};
int main()
{

    MyQueue<int> st(3);
    st.enqueue(234);
    st.enqueue(454);
    st.enqueue(765);

    MyQueue<char> stChar(4);
    stChar.enqueue('A');
    stChar.enqueue('%');
    stChar.enqueue('&');
    stChar.enqueue('W');
    MyQueue<string> stString(2);
    stString.enqueue("Today is");
    stString.enqueue("Friday");

    st.show();       // output : 234 454 75
    stChar.show();   // output : A % & W
    stString.show(); // output : Today is Friday

    st.dequeue();
    st.show(); // output : 454 75

    stChar.dequeue();
    stChar.dequeue();
    stChar.show(); // output : & W

    stString.dequeue();
    stString.dequeue();
    stString.show(); // output : Queue is empty

    // system("pause");
    return 0;
}