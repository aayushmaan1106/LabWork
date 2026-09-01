#include<iostream>
using namespace std;
int main(){
    int num;
    int sum = 0;
    cout<<"Enter The Value of num = ";
    cin>>num;
    while(num>0){
        sum = sum + num%10 ;
        num /= 10;
    }
    cout<<"sum = "<<sum;
    return 0;
}