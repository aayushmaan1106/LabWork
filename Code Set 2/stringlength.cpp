#include<iostream>
#include<string>
using namespace std ;

class text{
    private:
        string name ;
    public:
        text(string n = "")
        : name(n) {} 
    void set(){
        cout<<"enter the string name= " << endl ;
        cin >> name ;
    }
    void get() {
        int length = 0;
        for (char c : name) {
            length++;
        }
        cout<<" length value = " << length << endl ;
    }
};          

int main(){
    text s1(" ") ;
    s1.set() ;
    s1.get() ;
    return 0 ;
}