// Q1

#include <iostream>
using namespace std;

void input_vector(int size,int arr[])
{   
       for(int j=0;j<size;j++)
        {
        cin>>arr[j];
        }   
}

void print_vector(int size,int arr[]){
    
    for (int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void add_vector(int size,int arr1[],int arr2[],int sum_arr[]){
    for (int i=0;i<size;i++){
        sum_arr[i] =arr1[i]+arr2[i]; 
    }
    
}

void substract_vector(int size,int arr1[],int arr2[],int sub_arr[]){
    for (int i=0;i<size;i++){
        sub_arr[i] =arr1[i]-arr2[i]; 
    }
    
}

string compare_vector(int size,int arr1[],int arr2[]){
     for (int i=0;i<size;i++){
         bool isEqual;
        isEqual = arr1[i]==arr2[i]; 
        if (!isEqual){
            return "UNEQUAL";
        }
    }
    return "EQUAL";
}

int main(){
    int n;
    char opt;
    cin>>n;
    
    int v1[n],v2[n],sum_arr[n],sub_arr[n];
    input_vector(n, v1);
    input_vector(n,v2);
    
    cin>>opt;
    
    switch (opt)
    {
       case '+':
            add_vector(n,v1,v2,sum_arr);
            print_vector(n, sum_arr);
       break; 
       
       case '-':
            substract_vector(n,v1,v2,sub_arr);
            print_vector(n, sub_arr);
        break;
        
        case '=':
            cout<<compare_vector(n, v1, v2);
        break;
    }
    return 0;
}


// Q2

// Enter your code here.
#include <iostream>
using namespace std;



void input_matrix(int size,int arr[])
{   
       for(int j=0;j<size;j++)
        {
        cin>>arr[j];
        }   
}

void print_matrix(int row,int col,int arr[]){   
    for (int i=0;i<row*col;i++){
        cout<<arr[i]<<" ";
        if(i==row){
            cout<<endl;
        }
    }
}

void add_matrix(int size,int arr1[],int arr2[],int sum_arr[]){ 
    for (int i=0;i<size;i++){
        sum_arr[i] =arr1[i]+arr2[i]; 
    }
    
}

void subtract_matrix(int size,int arr1[],int arr2[],int sub_arr[]){
    for (int i=0;i<size;i++){
        sub_arr[i] =arr1[i]-arr2[i]; 
    }
    
}


int main(){
    int row,col,n;
    char opt;
    cin>>row>>col;
    
    n=row*col;
    int v1[n],v2[n],sum_arr[n],sub_arr[n];
    input_matrix(n, v1);
    input_matrix(n,v2);
    
    cin>>opt;
    
    switch (opt)
    {
       case '+':
            add_matrix(n,v1,v2,sum_arr);
            print_matrix(row,col, sum_arr);
       break; 
       
       case '-':
            subtract_matrix(n,v1,v2,sub_arr);
            print_matrix(row,col, sub_arr);
        break;
        
    }
    
    
    return 0;
}


// Q5

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
/* Enter your code here. Read input from STDIN. Print output to STDOUT */

void input_years(int yrs[],int size){
    for (int i=0;i<size;i++){
        int tmp_yr;
        cin>>tmp_yr;
        while(tmp_yr<0 || tmp_yr>9999){
            cout<<"Year can be between 0 and 9999! Try Again!"<<endl;
            cin>>tmp_yr;
        }
        yrs[i]=tmp_yr;
    }
}
void print_years(int yrs[],int size){
    for (int i=0;i<size;i++){
        cout<<yrs[i];
        if(i<size-1){
            cout<<", ";
        }else{
            cout<<endl;
        }
    }
}


void chronological_order(int yrs[],int size){
       for (int i=0;i<size;i++){
            for (int j=0;j<size-i-1;j++){
                if(yrs[j]>yrs[j+1]){
                    int tmp;
                    tmp = yrs[j];
                    yrs[j]=yrs[j+1];
                    yrs[j+1]=tmp;
            }
        }
    }
}


int main(){
    int n;
    cin>>n;
    while(n<2){
        cout<<"Need at least 2 years to sort! Try Again!"<<endl;
        cin>>n;
    }
    int yrs[n];
    input_years(yrs,n);
    cout<<"The initial array is: ";
    print_years(yrs, n);
    chronological_order(yrs, n);
    cout<<"The sorted array is: ";
    print_years(yrs, n);
    return 0;
}

// Q2

