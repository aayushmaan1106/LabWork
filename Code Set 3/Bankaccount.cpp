#include<iostream>
using namespace std ;
/*
class bankaccount{
    public:  
        int accno ;
        int balance ;
    void transfer(bankaccount a1 , bankaccount &a2) {
        cout<<"Account Details of the Account A1 = " << a1.accno << endl ;
        cout<<"Bank Balance Of A1 =" << a1.balance << endl ;
        cout<<"Account Details of the Account A2 = " << a2.accno << endl ;
        cout<<"Bank Balance Of A2 =" << a2.balance << endl ;        
    }
};

int main(){
    bankaccount d1 , d2   ;
    d1.accno = 909092 ;
    d1.balance = 200 ;
    d2.accno = 909091 ;
    d2.balance = 300 ; 
    d1.transfer(d1 , d2) ;

}
*/
#include<iostream>
using namespace std;

class bankaccount {
    public:  
        int accno;
        int balance;
    void transfer(bankaccount &receiver, int amount) {
        if (amount <= balance) {
            balance -= amount;         
            receiver.balance += amount; 
            cout << "Successfully transferred " << amount << " units.\n" << endl;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }
};

int main() {
    bankaccount d1, d2;
    
    d1.accno = 909092;
    d1.balance = 200;
    
    d2.accno = 909091;
    d2.balance = 300; 

    cout << "--- Before Transfer ---" << endl;
    cout << "Account D1: " << d1.accno << " | Balance: " << d1.balance << endl;
    cout << "Account D2: " << d2.accno << " | Balance: " << d2.balance << endl;
    cout << "-----------------------\n" << endl;

    // d1 calls the function to transfer 50 to d2
    d1.transfer(d2, 50);

    cout << "--- After Transfer ---" << endl;
    cout << "Account D1: " << d1.accno << " | Balance: " << d1.balance << endl;
    cout << "Account D2: " << d2.accno << " | Balance: " << d2.balance << endl;

    return 0;
}