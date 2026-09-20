#include <iostream>
using namespace std;

class Student {
public:
    static int count;

    Student() {
        count++;
        cout << "Student Created" << endl;
    }
};

int Student::count = 0;

int main() {
    Student s1;
    Student s2;
    Student s3;
    cout << "Total Students = " << Student::count << endl;
    return 0;
}