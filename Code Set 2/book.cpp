#include<iostream>
#include<string>
using namespace std ;

class book{
    private: 
        string title ;
        string author ;
    public: 
        book(string t , string a) 
        : title(t) , author(a) {}
        void set(){
            cout<<"Title Of the Book " ;
            cin >> title ;
            cout<<"Author of the Book" ;
            cin >> author ;
        }
        void details(){
            cout<<"book details are " << endl ;
            cout<<"the Title is  =" << title << endl ;
            cout<<"the author is =" << author << endl ;
        }
};

int main(){
    book b1(" " , " ") ;
    book b2(" " , " ") ;
    b1.set() ;
    b1.details();
    b2.set() ;
    b2.details();
    return 0;
}