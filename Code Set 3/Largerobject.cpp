#include<iostream>
using namespace std ;
class student{
    public:
        int rollno ;
        int marks ;
};

student findtop(student s1 , student s2){
    if(s1.marks > s2.marks){
        cout<<"The Marks Of Student 1 is Larger"<< endl ;
        return s1 ;
    }
    else if(s1.marks = s2.marks){
        cout<<"equal marks of student"<<endl ;
        return s1 ;
    }
    else{
        cout<<"The Marks of Student 2 is Larger"<<endl ;
        return s1 ;
    }
}

int main(){
    student s3 , s4 , highest ; 
    s3.rollno = 2 ;
    s3.marks = 10;
    s4.rollno = 4 ;
    s4.marks = 20 ;
    cout<<"enter roll of student 1 = "<< s3.rollno<< endl;
    cout<<"enter marks of student 1 = "<< s3.marks<< endl ;
    cout<<"enter roll of student 2  = "<< s4.rollno<< endl ;
    cout<<"enter marks of student 2 = "<< s4.marks<< endl ;  
    highest =  findtop(s3 , s4) ;
    cout<<"Here Are The results highest marks =" << highest.marks<<" Roll no = "<< highest.rollno << endl ;
}