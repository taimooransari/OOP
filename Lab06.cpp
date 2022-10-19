// q1
#include <iostream>
using namespace std;

class Complex
{
private:
    double real, imag;

public:
    Complex(double x, double y)
    {
        real = x;
        imag = y;
    }
    Complex()
    {
        real = 0;
        imag = 0;
    }

    void show()
    {
        if (real != 0)
        {
            cout << real;
        }
        if (imag > 0)
        {
            cout << "+";
        }
        if (imag != 0)
        {
            cout << imag << "i" << endl;
        }
    }

    Complex add(Complex c2)
    {
        double a = real + c2.real;
        double b = imag + c2.imag;

        return {a, b};
    }

    Complex add(double d1)
    {
        double a = real + d1;

        return {a, imag};
    }

    Complex subtract(Complex c2)
    {

        double a = real - c2.real;
        double b = imag - c2.imag;

        return {a, b};
    }

    Complex subtract(double d1)
    {

        double a = real - d1;

        return {a, imag};
    }

    Complex multiply(Complex c2)
    {
        double a = real * c2.real - imag * c2.imag;
        double b = real * c2.imag + imag * c2.real;

        return {a, b};
    }

    Complex multiply(double d1)
    {
        double a = real * d1;
        double b = imag * d1;

        return {a, b};
    }
};

int main()
{
    double real, imag;
    cin >> real >> imag;
    Complex c1 = {real, imag};

    cin >> real >> imag;
    Complex c2 = {real, imag};

    double d1;
    cin >> d1;

    Complex result;
    // showing the numbers:
    cout << "c1: ";
    c1.show();
    cout << "c2: ";
    c2.show();
    cout << "d1: " << d1 << endl;

    // Check the opertions where both operands are complex
    result = c1.add(c2);
    cout << "c1+c2: ";
    result.show();

    result = c1.subtract(c2);
    cout << "c1-c2: ";
    result.show();

    result = c1.multiply(c2);
    cout << "c1*c2: ";
    result.show();

    // Check the opertions where one operator is complex, other is double

    result = c1.add(d1);
    cout << "c1+d1: ";
    result.show();

    result = c1.subtract(d1);
    cout << "c1-d1: ";
    result.show();

    result = c1.multiply(d1);
    cout << "c1*d1: ";
    result.show();
}

// q2
#include <iostream>
using namespace std;

class Time24
{
private:
    int hours;
    int min;
    int sec;
    char pm_am;

    void adjust()
    {
        if (pm_am == 'p')
        {
            hours += 12;
        }
        pm_am = '\0';
    }

public:
    // default constructor
    Time24()
    {
        hours = 0;
        min = 0;
        sec = 0;
        pm_am = '\0';
    }

    // 24 hr format
    Time24(int h, int m, int s)
    {
        hours = h;
        min = m;
        sec = s;
        pm_am = '\0';

        if (sec >= 60)
        {
            min += sec / 60;
            sec = sec % 60;
        }

        if (min >= 60)
        {
            hours += min / 60;
            min = min % 60;
        }

        if (hours >= 24)
        {

            hours = hours % 24;
        }
    }
    // 12 hr format
    Time24(int h, int m, int s, char p)
    {

        hours = h;
        min = m;
        sec = s;
        pm_am = p;

        if (sec >= 60)
        {
            min += sec / 60;
            sec = sec % 60;
        }

        if (min >= 60)
        {
            hours += min / 60;
            min = min % 60;
        }

        adjust();
        if (hours >= 24)
        {
            hours %= 24;
        }
    }

    // show

    void show()
    {
        adjust();
        if (hours < 10)
        {
            cout << '0';
        }

        cout << hours << ":";

        if (min < 10)
        {
            cout << '0';
        }

        cout << min << ":";
        if (sec < 10)
        {
            cout << '0';
        }

        cout << sec << endl;
    }

    // add
    void add(Time24 t2)
    {
        adjust();
        t2.adjust();

        sec += t2.sec;
        if (sec >= 60)
        {
            min += sec / 60;
            sec = sec % 60;
        }

        min += t2.min;
        if (min >= 60)
        {
            hours += min / 60;
            min = min % 60;
        }

        hours += t2.hours;

        if (hours >= 24)
        {

            hours = hours % 24;
        }
    }
};

int main()
{
    int hours1, minutes1, seconds1;
    cin >> hours1 >> minutes1 >> seconds1;
    Time24 t1(hours1, minutes1, seconds1);

    int hours2, minutes2, seconds2;
    char period;
    cin >> hours2 >> minutes2 >> seconds2 >> period;
    Time24 t2 = {hours2, minutes2, seconds2, period};

    cout << "t1: ";
    t1.show();
    cout << "t2: ";
    t2.show();

    t1.add(t2); // result of addition is stored in t1
    cout << "t1+t2: ";
    t1.show();
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

class Tollbooth
{
private:
    int cars, cash;

public:
    Tollbooth()
    {
        cars = 0;
        cash = 0;
    }

    void payingCar()
    {
        cars += 1;
        cash += 50;
    }

    void nopayCar()
    {
        cars += 1;
    }

    void display()
    {
        cout << "Total cars passed: " << cars << endl;
        cout << "Total toll collected: Rs. " << cash << endl;
    }
};

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Tollbooth toll;
    char car_passed;
    cin >> car_passed;

    while (car_passed != 'q')
    {
        if (car_passed == 'p')
        {
            toll.payingCar();
        }
        else if (car_passed == 'n')
        {
            toll.nopayCar();
        }

        cin >> car_passed;
    }

    toll.display();
    return 0;
}

// q4

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

// 1. Define the Student class here

class Student
{
public:
    long int id;
    char firstName[100];
    char lastName[100];
    double score;
    //    show
    void show()
    {
        cout << id << endl;
        cout << firstName << endl;
        cout << lastName << endl;
        cout << score << endl;
    }
};

// 2. Define the MinMax function here
Student *MinStudent(Student *arr, int size)
{

    int ind = 0;
    double min = 100;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].score < min)
        {
            ind = i;
            min = arr[i].score;
        }
    }
    return arr + ind;
}

Student *MaxStudent(Student *arr, int size)
{
    int ind = 0;
    double max = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].score > max)
        {
            ind = i;
            max = arr[i].score;
        }
    }
    return arr + ind;
}

// 3. Do the necessary steps in the main function
int main()
{
    // 1. create Student array of size n dynamically

    int n;
    cin >> n;
    Student *arr = new Student[n];

    // 2. Read the Student information into the Student array
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i].id;
        cin.ignore();
        cin.getline(arr[i].firstName, 100, '\n');
        cin.getline(arr[i].lastName, 100, '\n');
        cin >> arr[i].score;
    }

    // 3. Pass the student array to the MinStudent function and store returned value in pointer of type Student
    Student *min_std = MinStudent(arr, n);

    // 4. Pass the student array to the MaxStudent function and store returned value in pointer of type Student
    Student *max_std = MaxStudent(arr, n);
    cout << "Student with Minimum score:" << endl;

    // 5. Call Student's show() function to print the student information of the object returned by MinStudent function.
    min_std[0].show();
    cout << endl;

    cout << "Student with Maximum score:" << endl;
    // 6. Call Student's show() function to print the student information of the object returned by MaxStudent function.

    max_std[0].show();
    // 7. Delete the array
    delete[] arr;
    return 0;
}