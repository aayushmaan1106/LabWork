#include<iostream>
using namespace std;
int main(){
    int num,orignalnum,remainder;
    int reversednum=0;
    cout<<"Num =";
    cin>>num;
    orignalnum = num ;
    while(num > 0){
        remainder = num % 10;
        reversednum = reversednum*10 + remainder;
        num /= 10;
    }
    if(orignalnum == reversednum){
        cout<<orignalnum<<"the number is palindrome";
    }
    else{
        cout<<"number is not palindrome";
    }
    return 0;
}