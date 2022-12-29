// Enter your code here.
#include <iostream>
using namespace std;

class Thug
{

    string name;
    string symbol;

public:
    Thug(string n = "", string s = "")
    {
        name = n;
        symbol = s;
    };
    string getName()
    {
        return name;
    }
    virtual void slogan() = 0;
    ~Thug();
};

class Karkun : public Thug
{
public:
    Karkun();
    Karkun(string n) : Thug(n, "kite")
    {
    }
    void slogan()
    {
        cout << getName() << " bhai: Churan kha lo." << endl;
    }
    ~Karkun();
};

class Jiyala : public Thug
{
public:
    Jiyala();
    Jiyala(string n) : Thug(n, "arrow")
    {
    }
    void slogan()
    {
        cout << getName() << " shaheed: Democracy is the best revenge." << endl;
    }
    ~Jiyala();
};

class Ligi : public Thug
{
public:
    Ligi();
    Ligi(string n) : Thug(n, "lion")
    {
    }
    void slogan()
    {
        cout << "Mian " << getName() << ": Kyun Nikala?" << endl;
    }
    ~Ligi();
};

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    Thug **arr = new Thug *[n];
    string type;
    string name;
    cin.ignore();
    for (int i = n - 1; i >= 0; i--)
    {
        getline(cin, name);
        getline(cin, type);
        if (type == "kite")
        {
            arr[i] = new Karkun(name);
        }
        else if (type == "lion")
        {
            arr[i] = new Ligi(name);
        }
        else if (type == "arrow")
        {
            arr[i] = new Jiyala(name);
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i]->slogan();
    }

    // for (int i=0;i<n;i++){
    //     delete arr[i];
    // }
    delete[] arr;
    return 0;
}