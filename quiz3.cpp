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
class Queue {
    int size; //Size of queue is its maximum capacity
    int* array; //Integer array of fixed size
    int head; //Index of the oldest item in the array
    int tail; //Index of the most-freshly enqueued item in the array
    int count; //Count of items from head to tail
    
    public:
    Queue(int _size) {
        /* Initializes a Queue of given size */
        size=_size;
        array = new int[size];
        count = 0;
    }
    
    ~Queue() {
        /* Releases any memory allocated on heap */
        delete [] array;
    }

    void Enqueue(int new_item) {
        /* Adds a new item in the Queue */
        if(count==size){
            cout<<"Out of space"<<endl;
            return;
        }
        else{
            if(count ==0){
                array[0] = new_item;
                head =0;
                tail=0;
                          }
            else{
                array[tail+1]=new_item;
                tail++;
                 }
        count++; 
       }
    }
    
    int Dequeue() {
        /* Returns the oldest item and removes it from the Queue */
        if(count!=0){
            
            int tmp = array[head];
            for(int i=0;i<count;i++){
                array[i] = array[i+1];
            }
            tail--;
            count--;
          return tmp;
        }
        
        cout<<"Out of items"<<endl;
        return -1;
    }
    
    int ItemCount() {
        /* Returns the total no. of items the Queue is holding currently */
        return tail-head+1;
    }
};


int main() {
    int size_;
    cin >> size_;
    Queue q(size_);
    char Op[50];
    while(cin >> Op) {
        if(strcmp(Op, "Enqueue") == 0) {
            int item;
            cin >> item;
            q.Enqueue(item);
        }
        else if(strcmp(Op, "Dequeue") == 0) {
            int item = q.Dequeue();
            if (item != -1)
                cout << item << endl;
        }
        else if(strcmp(Op, "Count") == 0) {
            cout << q.ItemCount() << endl;
        }
        else {
            break;
        }
    }
    return 0;
}
