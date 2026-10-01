#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    int accountNumber;
    float balance;

public:
    Account(int a, float b)
    {
        accountNumber = a;
        balance = b;
    }

    virtual void display()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account
{
private:
    float interestRate;

public:
    SavingsAccount(int a, float b, float i)
        : Account(a, b)
    {
        interestRate = i;
    }

    void display()
    {
        cout << "Savings Account" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << endl;
    }
};

class CurrentAccount : public Account
{
private:
    float overdraftLimit;

public:
    CurrentAccount(int a, float b, float o)
        : Account(a, b)
    {
        overdraftLimit = o;
    }

    void display()
    {
        cout << "Current Account" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Overdraft Limit: " << overdraftLimit << endl;
        cout << endl;
    }
};

int main()
{
    SavingsAccount s1(1001, 25000, 5.5);
    SavingsAccount s2(1002, 40000, 6.0);

    CurrentAccount c1(2001, 50000, 10000);
    CurrentAccount c2(2002, 75000, 15000);

    s1.display();
    s2.display();
    c1.display();
    c2.display();

    return 0;
}