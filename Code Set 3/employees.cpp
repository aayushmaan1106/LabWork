#include <iostream>
#include <string>

class Employee {
public:
    std::string name;
    double salary;

    Employee() {}
    Employee(std::string n, double s) : name(n), salary(s) {}
};

Employee getHighestSalary(Employee employees[], int size) {
    Employee highest = employees[0];
    for (int i = 1; i < size; i++) {
        if (employees[i].salary > highest.salary) {
            highest = employees[i];
        }
    }
    return highest;
}

Employee giveIncrement(Employee emp) {
    emp.salary = emp.salary * 1.10;
    return emp;
}

int main() {
    Employee staff[3] = {
        Employee("Alice", 50000),
        Employee("Bob", 65000),
        Employee("Charlie", 55000)
    };

    Employee richest = getHighestSalary(staff, 3);
    std::cout << "Highest Salary: " << richest.name << " with $" << richest.salary << std::endl;

    Employee updatedBob = giveIncrement(staff[1]);
    std::cout << "Bob's Revised Salary: $" << updatedBob.salary << std::endl;

    return 0;
}
