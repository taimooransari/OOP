#include <iostream>

#include <string>
using namespace std;

// Write your code here.
int steel_grade(int hardness,float carbon_content,int tensile_strength){
    bool cond1 = hardness>50;
    bool cond2 = carbon_content<0.7;
    bool cond3 = tensile_strength>5600;
    int grade = 5;
    if(cond1&&cond2&&cond3)
    {
        grade= 10;
    }
    else if(cond1&&cond2)
    {
        grade= 9;
    }
    else if(cond2&&cond3)
    {
        grade= 8;
    }
    else if(cond1&&cond3)
    {
        grade =  7;
    }
    else if(cond1^cond2^cond3)
    {
        grade= 6;
    }
    
    return grade;
}

int main() {
  int hardness, tensile_strength;
  float carbon_content;
  std::cin >> hardness >> carbon_content >> tensile_strength;
  std::cout << steel_grade(hardness, carbon_content, tensile_strength);
  return 0;
}

// =====================================

#include <iostream>

#include <string>
using namespace std;
void race(int prime_up,int prime_down,int tron_up,int tron_down)
{
    bool isRaceFinished = false;
    int prime_position=0,tron_position =0,jumps=0; 
    while (!isRaceFinished)
    {
        jumps++;
        cout<<"Jump "<<jumps<<endl;
        prime_position+=prime_up;
        tron_position+=tron_up;
        if(prime_position>=1000 || tron_position>=1000){
            if(prime_position>=1000 && tron_position>=1000){
                cout<<"Frog Prime has cleared the well!" <<endl;
                cout<<"Frogatron has cleared the well!" <<endl;
                cout<<"***** END OF RACE *****"<<endl;
                cout<<"TIE in "<<jumps<<" jumps!"<<endl;
            }
            else if(prime_position>=1000)
            {
                cout<<"Frog Prime has cleared the well!" <<endl;
                cout<<"Frogatron is at "<<tron_position-tron_down<<" meters."<<endl; 
                cout<<"***** END OF RACE *****"<<endl;
                cout<<"Frog Prime wins in "<<jumps<<" jumps!"<<endl;
            }
            else
            {
                cout<<"Frog Prime is at "<<prime_position-prime_down<<" meters."<<endl;
                cout<<"Frogatron has cleared the well!" <<endl;
                cout<<"***** END OF RACE *****"<<endl;
                cout<<"Frogatron wins in "<<jumps<<" jumps!"<<endl;
            }
            isRaceFinished=true;
        }
        else
        {
            prime_position-=prime_down;
            tron_position-=tron_down;
           cout<<"Frog Prime is at "<<prime_position<<" meters."<<endl;
           cout<<"Frogatron is at "<<tron_position<<" meters."<<endl; 
        }
        
    }
}
int main(int argc, char** argv) {
  int prime_up, prime_down, tron_up, tron_down;
  std::cin >> prime_up >> prime_down >> tron_up >> tron_down;
  race(prime_up, prime_down, tron_up, tron_down);
  return 0;
}

// ===================

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
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int term0,term1,n;
    cin>>term0>>term1>>n;
    cout<<term0;
    if(n>0){
    for (int i = 0;i<n;i++){
            cout<<", "<<term1; 
            int tmp;
            tmp = term0;
            term0=term1;
            term1+=tmp;       
            }
    }
    return 0;
}

// ===============

#include<iostream>
using namespace std;
int returnHoles(int n){
    
    if(n==1||n==2||n==3||n==5||n==7){
        return 0;
    }else if(n==0||n==4||n==6||n==9){
        return 1; 
    }
    else{
        return 2;
    }
}

int countHoles(int num){
    int divider =10,holes=0;
    
    while (num !=0 )
    {
        int rem = (num%divider);
        holes+=returnHoles(rem*10/divider);
        divider*=10;
        num = num-rem;
    }
    return holes;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num;
    cin>>num;
    cout<<countHoles(num)<<" holes";
    return 0;
}

// ==================================
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
int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int base,exponent;
    cin>>base>>exponent;
    bool isInvalid = false;
    
    isInvalid = (base>10 || base<1) || (exponent>5 || exponent<0);
    if(isInvalid){
        cout<<"Invalid input!";
    }
    else{
        cout<<base<<" to the power of "<<exponent<<" is: "<<pow(base,exponent);
    }
    return 0;
}

// ===================


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
int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int base,exponent;
    cin>>base>>exponent;
    bool isInvalid = false;
    
    isInvalid = (base>10 || base<1) || (exponent>5 || exponent<0);
    if(isInvalid){
        cout<<"Invalid input!";
    }
    else{
        int result=1;
        for (int i=0;i<exponent;i++){
            result*=base;
        }
        cout<<base<<" to the power of "<<exponent<<" is: "<<result;
    }
    return 0;
}