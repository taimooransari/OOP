#include <iostream>
using namespace std;

class Publication
{
private:
    string title;
    float price;

public:
    void getdata()
    {
        getline(cin, title);
        cin >> price;
    }
    void putdata()
    {
        cout << "Publication title: " << title << endl;
        cout << "Publication price: " << price << endl;
    }
};

class book : public Publication
{
private:
    int page_count;

public:
    void getdata()
    {
        Publication::getdata();
        cin >> page_count;
    }
    void putdata()
    {
        Publication::putdata();
        cout << "Book page count: " << page_count << endl;
    }
};

class tape : public Publication
{
private:
    float play_time;

public:
    void getdata()
    {
        Publication::getdata();
        cin >> play_time;
    }

    void putdata()
    {
        Publication::putdata();
        cout << "Tape's playing time: " << play_time << endl;
    }
};

int main()
{
    book b;
    tape t;
    b.getdata();
    cin.ignore();
    t.getdata();
    b.putdata();
    t.putdata();
}

// q2

#include <iostream>
using namespace std;

class Payment
{
private:
    double amount;

public:
    void setAmount(double a)
    {
        amount = a;
    }
    double getAmount()
    {
        return amount;
    }
    void paymentDetails()
    {
        cout << "Amount of cash payment: $" << amount << endl;
    }
};

class CashPayment : public Payment
{
public:
    CashPayment(double a)
    {
        Payment::setAmount(a);
    }
};

class CreditCardPayment : public Payment
{
private:
    string name;
    string date;
    string cred_num;

public:
    CreditCardPayment(double a, string n, string d, string cr)
    {
        Payment::setAmount(a);
        name = n;
        date = d;
        cred_num = cr;
    }
    void paymentDetails()
    {
        cout << "Amount of credit card payment: $" << Payment::getAmount() << endl;
        cout << "Name on the credit card: " << name << endl;
        cout << "Expiration date: " << date << endl;
        cout << "Credit card number: " << cred_num << endl;
    }
};

int main()
{
    CashPayment cp1(75.25);
    CashPayment cp2(36.95);
    CreditCardPayment ccp1(95.15, "Smith", "12/21/2009", "321654987");
    CreditCardPayment ccp2(45.75, "James", "10/30/2008", "963852741");

    cout << "Details of Cash #1..." << endl;
    cp1.paymentDetails();

    cout << "\nDetails of Cash #2..." << endl;
    cp2.paymentDetails();

    cout << "\nDetails of Credit Card #1..." << endl;
    ccp1.paymentDetails();

    cout << "\nDetails of Credit Card #2..." << endl;
    ccp2.paymentDetails();

    return 0;
}

// q3

#include <iostream>
using namespace std;

class TollBooth
{
    int totalCars;
    double toll;

public:
    TollBooth() : totalCars(0), toll(0) {}
    void payingCar()
    {
        totalCars++;
        toll += 50;
    }

    void nopayCar()
    {
        totalCars++;
    }

    void display() const
    {
        cout << "Total cars passed: " << totalCars << endl;
        cout << "Total toll collected: Rs. " << toll << endl;
    }
};

// provide LyariTollBooth class implementation, and write main function.

class LyariTollBooth : public TollBooth
{
private:
    double fine;

public:
    LyariTollBooth()
    {
        fine = 0;
    }
    void nopayCar()
    {

        TollBooth::nopayCar();
        fine += 500;
    }
    void display()
    {
        TollBooth::display();
        cout << "Total fine collected: Rs. " << fine << endl;
    }
};

int main()
{
    char chr;
    LyariTollBooth booth;
    while (chr != 'q')
    {
        cin >> chr;
        if (chr == 'p')
        {
            booth.payingCar();
        }
        else if (chr == 'n')
        {
            booth.nopayCar();
        }
    }
    booth.display();

    return 0;
}