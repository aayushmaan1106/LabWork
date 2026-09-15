#include<iostream>
using namespace std;

class number{
    public:
    int integer ;
};
number sum(number n1 , number n2){
    number add;
    add.integer = n1.integer + n2.integer;
    return add ;
}
int main(){
    number p , q , result ;
    cout<<"Enter the details of two numbers"<< endl ;
    cin>>p.integer ;
    cin>>q.integer;
    result = sum(p,q);
    cout<<result.integer ;
    return 0 ;
}
