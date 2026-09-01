#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the value of n= ";
    cin>>n;
    int *arr = new int[n];
    cout<<"enter the values of array you need = ";
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    cout<<"you entered Values of array = "<<endl;
    for(int i = 0; i < n ; i ++){
        cout<<arr[i];
    }
    int largest = arr[n];
    for(int i = 0 ; i < n ; i ++){
        if(largest < arr[i]){
            largest = arr[i];
        }
    }
    cout<<"The Largest Element of Array is = "<<largest<<endl;
    delete[] arr;
    return 0;
}