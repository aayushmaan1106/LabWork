#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string employeeName;
    double basicSalary;

public:
    Employee(string name, double salary) {
        employeeName = name;
        basicSalary = salary;
    }

    double calculateHRA() {
        return 0.20 * basicSalary;
    }

    double calculateDA() {
        return 0.10 * basicSalary;
    }

    void displayGrossSalary() {
        double hra = calculateHRA();
        double da = calculateDA();
        double grossSalary = basicSalary + hra + da;

        cout << "\n--- Salary Statement ---" << endl;
        cout << "Employee Name: " << employeeName << endl;
        cout << "Basic Salary : $" << basicSalary << endl;
        cout << "HRA (20%)    : $" << hra << endl;
        cout << "DA (10%)     : $" << da << endl;
        cout << "------------------------" << endl;
        cout << "Gross Salary : $" << grossSalary << endl;
    }
};

int main() {
    Employee emp("Tawqeer ul Islam", 50000);
    emp.displayGrossSalary();
    return 0;
}
