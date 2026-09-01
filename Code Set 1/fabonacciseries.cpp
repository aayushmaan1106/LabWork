#include<iostream>
using namespace std;
int main(){
    int n;
    int t1 = 0 , t2 = 1 ,nextterm = 0;
    cout<<"Enter the value of n";
    cin>>n;
    cout<<"Fabonacci series";

    for(int i = 0; i < n ; i++){
        if(i == 1){
            cout<<t1<<endl;
            continue;
        }
        if(i == 2){
            cout<<t2<<" ";
        }
        nextterm=t2+t1;
        t1=t2;
        t2=nextterm;
        cout<<nextterm<<" ";
    }
    return 0;
}