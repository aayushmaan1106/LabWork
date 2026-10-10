#include <iostream>

using namespace std;

class BankAccount {
    double balance;
public:
    BankAccount(double b) {
        balance = b;
    }
    void withdraw(double amount) {
        if (amount > balance) {
            throw "Error: Insufficient Balance.";
        }
        balance -= amount;
        cout << "Remaining Balance: " << balance << endl;
    }
};

int main() {
    double bal, amt;
    cin >> bal >> amt;
    BankAccount acc(bal);
    try {
        acc.withdraw(amt);
    } catch (const char* msg) {
        cout << msg << endl;
    }
    return 0;
}