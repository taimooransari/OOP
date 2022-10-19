#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{

    Node *Head;

public:
    LinkedList()
    {
        Head = NULL;
    }

    // Insert Item with data n at the First Position
    void Insert(int n)
    {
        Node *newHead = new Node[1];
        newHead->data = n;
        newHead->next = Head;
        Head = newHead;
    }
    // Insert Item with data =n at position = pos
    void Insert(int n, int pos)
    {

        Node *tmp_head = Head;
        for (int i = 0; i < pos-1; i++)
        {
            if (tmp_head->next == NULL and i != pos - 1)
            {
                cout << "THIS POSITION DOESN'T EXIST";
                return;
            }
            tmp_head = tmp_head->next;
        }

        Node *newHead = new Node[1];
        newHead->data = n;
        newHead->next = tmp_head->next;
        tmp_head->next = newHead;
    }

    void InsertAtEnd(int n)
    {
        Node *tmp_head = Head;
        while (tmp_head->next != NULL)
        {
            tmp_head = tmp_head->next;
        }

        Node *newHead = new Node[1];
        newHead->data = n;
        tmp_head->next = newHead;
    }

    // Delete First Item in the List
    void DeleteFirst()
    {
        Node *tmp = Head;
        Head = tmp->next;
        delete tmp;
    }

    // Delete item at position =pos
    void Delete(int pos)
    {
        Node *tmp_head = Head;
        for (int i = 0; i < pos; i++)
        {
            if (tmp_head->next == NULL and i != pos - 1)
            {
                cout << "THIS POSITION DOESN'T EXIST";
                return;
            }
            tmp_head = tmp_head->next;
        }
        Node *tmp = tmp_head->next;
        tmp_head->next = tmp->next;
        delete tmp;
    }

    void DeleteAtEnd()
    {
        Node *tmp_head = Head;

        while (tmp_head->next->next != NULL)
        {
            tmp_head = tmp_head->next;
        }
        delete tmp_head->next;
        tmp_head->next = NULL;
    }

    // Update item and set n as new data at position pos,
    void Update(int n, int pos)
    {
        Node *tmp_head = Head;
        for (int i = 0; i < pos ; i++)
        {
            if (tmp_head->next == NULL and i != pos - 1)
            {
                cout << "THIS POSITION DOESN'T EXIST";
                return;
            }
            tmp_head = tmp_head->next;
        }
        tmp_head->data = n;
    }

    void show()
    {
        Node *tmp_head = Head;
        while (tmp_head != NULL)
        {
            cout << tmp_head->data << " ";
            tmp_head = tmp_head->next;
        }
        cout << endl;
    }
};

int main()
{

    LinkedList ll;
    ll.Insert(10);
    ll.Insert(20); // and so all oter functions can be tested here!
    ll.show();
    ll.InsertAtEnd(30);
    ll.show();
    ll.Update(60,1);
    ll.Insert(44,1);
    // ll.DeleteAtEnd();
    // ll.show();
    // ll.DeleteFirst();
    ll.show();
    return 0;
}
