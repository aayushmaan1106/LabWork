#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
    string name;
    int rollNumber;
    int age;

public:
    Student(string n, int r, int a)
    {
        name = n;
        rollNumber = r;
        age = a;
    }
};

class EngineeringStudent : public Student
{
private:
    string branch;
    int semester;

public:
    EngineeringStudent(string n, int r, int a, string b, int s)
        : Student(n, r, a)
    {
        branch = b;
        semester = s;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Age: " << age << endl;
        cout << "Branch: " << branch << endl;
        cout << "Semester: " << semester << endl;
    }
};

int main()
{
    EngineeringStudent s1("Aayush", 101, 20, "CSE", 3);

    s1.display();

    return 0;
}