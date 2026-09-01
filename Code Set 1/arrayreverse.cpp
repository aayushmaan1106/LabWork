#include<iostream>
using namespace std;
int  main(){
    int n;
    cout<<"enter the value of array length you want";
    cin>>n;
    int arr[n];
    cout<<"enter the array=";
    for(int i=0 ; i < n; i++){
        cin>>arr[i];
    }
    cout<<"your entered array =";
     for(int i=0 ; i < n; i++){
        cout<<arr[i];
    }
    int start = 0;
    int end = n-1 ;
    while(start < end){
          int temp = arr[start];
          arr[start] = arr[end] ;
          arr[end] = temp;
          start ++;
          end --;
    }
    cout << "reversed array = " << endl;
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;


} 