#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    int employeeID;
    string name;

public:
    Employee(int id, string n)
    {
        employeeID = id;
        name = n;
    }
};

class Manager : public Employee
{
private:
    string department;
    float salary;

public:
    Manager(int id, string n, string d, float s)
        : Employee(id, n)
    {
        department = d;
        salary = s;
    }

    void display()
    {
        cout << "Employee ID: " << employeeID << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
        cout << endl;
    }
};

int main()
{
    Manager managers[5] =
    {
        Manager(101, "Rahul", "IT", 50000),
        Manager(102, "Aman", "HR", 55000),
        Manager(103, "Rohit", "Finance", 60000),
        Manager(104, "Karan", "Marketing", 52000),
        Manager(105, "Vikas", "Sales", 58000)
    };

    for(int i = 0; i < 5; i++)
    {
        managers[i].display();
    }

    return 0;
}