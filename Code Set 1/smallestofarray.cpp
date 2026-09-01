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
    int smallest = arr[n];
    for(int i = 0 ; i < n ; i ++){
        if(smallest > arr[i]){
            smallest = arr[i];
        }
    }
    cout<<"The smallest Element of Array is = "<<smallest<<endl;
    delete[] arr;
    return 0;
}