#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the value of number = ";
    cin >> n ;
    int arr[n];
    cout<<"enter the values of array you want"<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    cout<<"entred values of array = "<<endl;
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i];
    }
    int slargest = arr[0];
    for(int i = 1 ; i < n ; i ++){
        if(slargest < arr[i-1]){
            slargest = arr[i-1];
        }
    }
    cout<<"The Largest Element of Array is = "<<slargest<<endl;
    return 0;
}