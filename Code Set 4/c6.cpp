#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    int accNumber;
    string name;

public:
    static int totalAccounts;

    BankAccount(int acc, string n) {
        accNumber = acc;
        name = n;
        totalAccounts++;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }
};

int BankAccount::totalAccounts = 0;

int main() {
    BankAccount b1(101, "Alice");
    BankAccount b2(102, "Bob");
    cout << "Total Accounts = " << BankAccount::getTotalAccounts() << endl;
    return 0;
}