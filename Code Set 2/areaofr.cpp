#include<iostream>
#include<string>
using namespace std ;
class rectangle{ 
    private:
        float length ;
        float breadth ;
        float area ;
    public:
        rectangle(float l , float b )
        : length(l) , breadth(b)  {}
    void result(){
        cout<<"enter the value of length = " << length<<endl ;
        cout<<"enter the value of breadth = " << breadth << endl ; 
        area = length * breadth ;
        cout<<"area is = " <<area ;
    }    
}; 
int main(){
    rectangle r1(20 , 10) ;
    r1.result() ;
    return 0 ;
}