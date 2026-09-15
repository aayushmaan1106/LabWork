#include<iostream>
using namespace std ;
class Distance{
    public:
        int feet ;
        int inches ;
    void add(Distance d1 , Distance d2){
        feet = d1.feet + d2.feet;
        inches = d1.inches + d2.inches ; 
        if(inches > 12){
            feet++ ;
            inches -= 12 ;
        }
        cout<<"the feet = "<< feet << "total innches =" << inches << endl ;
    }
};

int main(){
    Distance d3,d4,result ;
    d3.feet = 10 ;
    d3.inches = 12 ;
    d4.feet = 10 ;
    d4.inches = 12 ;
    result.add(d3 , d4) ;
    return 0 ;
} 