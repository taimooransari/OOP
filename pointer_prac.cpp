#include<iostream>
#include<cstring>


using namespace std;
/// define sort() function here

void sort(char **arr, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            int res = strcmp(*(arr + j), *(arr + j + 1));
            if(res > 0){
                char *tmp = *(arr + j); 
                *(arr + j) = *(arr + j+1);
                 *(arr + j+1) = tmp;
            }
        }
    }
    
}


int main() 
{
    // write your main() code here
    int n; cin >> n; cin.ignore();
    char** arr = new char*[n];
    for(int i = 0; i < n; i++){
        *(arr + i) = new char[10000];
        cin.get(*(arr + i), 10000); cin.ignore();
    }
    
    sort(arr, n);
    
    for(int i = 0; i < n; i++){
        cout << *(arr + i) << endl;
    }
    
    for(int i = 0; i < n; i++){
        delete[] *(arr + i);
    }
    delete[] arr;
    
    return 0;
}