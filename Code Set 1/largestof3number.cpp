#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"enter 3 numbers to compare =";
    cin>>a>>b>>c;
    if(a>b && b>c){
        cout<<"First number is the largest number";
    }
    else if(b>a && a>c){
        cout<<"Second number is the largest number";

    }
    else{
        cout<<"Third number is the largest number";
    }

}