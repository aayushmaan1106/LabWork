#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"Enter The Number= ";
    cin>>num;
     if(num<0 && num == 1){
        cout<<"factorial of num < 0 doesnt exist";
        cout<<"factroial of 0 and 1 is 1 ";
     }
     long long factorial = 1;
     for(int i = 1; i <= num ;i++ ){
        factorial = factorial*i ;
     }
     cout<<"Value of factorial of" <<num<<"is"<<factorial;
}