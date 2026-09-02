#include<iostream>
using namespace std ; 
class oddeven{ 
    private:
        int number ;
    public:
        oddeven(int n)
        : number(n) {}
    void display(){
        if(number%2 == 0){
            cout<<"even number";
        }
        else{
            cout<<"odd number";
        }
    }
};

int main(){
    oddeven oe1(20);
    oe1.display() ;
    return 0 ;
}