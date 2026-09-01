#include<iostream>
using namespace std;
int main(){
    int num, remainder;
    int reversed = 0;
    cout<<"Value of Num";
    cin>>num;
    if(num<0){
        num = -num;
    }
    while(num > 0){
        remainder = num % 10;
        reversed = reversed*10 + remainder;
        num /= 10;
    }
    cout<<"reversed number is = "<<reversed;
    return 0;
}