#include<iostream>
#include<string>
using namespace std;
class student{
    private:
        string name ;
        int rollno ;
    public:
         void setdata(){
        cout << "enter the name of student " << endl ;
        cin >>name ;
        cout << "enter the rollno of student " << endl ;
        cin >> rollno ;
        }
        void displaydata(){
        cout << "enter student details" << endl ;
        cout << "enter the name" <<name << endl ;
        cout << "enter the roll number" << rollno<< endl ;
        }  
};

int main(){
    student s1 ;
    s1.setdata() ;
    s1.displaydata() ;
    return 0 ;
}