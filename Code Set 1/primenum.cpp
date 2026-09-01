#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"Value of number = ";
    cin>>num;
    if(num < 0){
        num = -num;
    }
    if(num == 1 && num == 0){
        cout<<"For 1 and 0 prime term doesnt exist";
    }
    for(int i = 2 ; i < num ; i++ ){
        if((num % i) == 0){
            cout<<"the number is not prime";
            break;
        }
        else{
            cout<<"the number is prime";
        }
    }
    return 0;
}