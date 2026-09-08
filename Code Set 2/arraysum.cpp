#include<iostream>
using namespace std ;

class arr{
    private:
        int number ;
    public: 
        arr(int n) 
        : number(n) {}
        int *array = new int[number] ;
        void set(){
            cout<<"entered details of array are = "<< endl ;
            for(int i = 0 ; i < number ; i ++ ){
                cin>>array[i] ;
            }
        }
        void get(){
            int sum = 0 ;
            cout<<"entered details are = "<< endl ;
            for(int i = 0 ; i < number ; i++){
                cout<<array[i] ;
            }
            for(int i = 0 ; i < number ; i++){
                sum += array[i];
            }
        cout<<"sum of the array is = "<< sum << endl;
       }
};
 
int main(){
    int p ;
    cout<<"the value of p = " ;
    cin >> p; 
    arr a1(p) ;
    a1.set() ;
    a1.get() ;
    return 0 ;

}