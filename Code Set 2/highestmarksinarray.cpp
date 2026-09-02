#include<iostream>
using namespace std ;

class Marks{
    private:
        int number ;
    public:
        Marks(int n)
        : number(n) {}
    int *array = new int[number] ;
    void set(){
        cout<<"enter marks of 5 students" << endl ;
        for(int i = 0 ; i < number ; i ++ ){
                cin>>array[i] ;
            }
    }
    void get(){
        int largest = array[0];
        cout<<"entered details are = "<< endl ;
        for(int i = 0 ; i <number ; i++){
                cout<<array[i] ;
            }
        for(int i = 1 ; i < number ; i++){
            if(array[i] > largest){
                largest = array[i];
            }
        }
        cout<<"largest marks in array is = " << largest <<endl ;
    }
    
};

int main(){
    Marks m(5) ;
    m.set();
    m.get();
    return 0;
}