#include<iostream>
#include<string>
using namespace std ;

class bankaccount{
    private:
        long long  accountnum ;
        float balance ;
    public:
        bankaccount(long long a,float b)
        : accountnum(a) , balance(b) {}
    void set(){
        cout<<"bank account details are = "<< endl ;
    } 
    void get(){
        cout<<"entered account details are given as = "<< endl  ;
        cout<<"account number ="<< accountnum << endl ;
        cout<<"account balance = "<< balance << endl ; 
    }
};

int main(){
    int p , q ;
    cout<<"enter values of account num  and balance" ;
    cin>>p ; 
    cin >> q ;
    bankaccount ba1(p , q) ;
    ba1.set() ;
    ba1.get() ;
    return 0 ;
}