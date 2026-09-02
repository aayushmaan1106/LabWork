#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int rollNo;
    double marks[5];

public:
    Student(string sName, int rNo, double m[]) {
        name = sName;
        rollNo = rNo;
        for (int i = 0; i < 5; i++) {
            marks[i] = m[i];
        }
    }

    double calculateTotal() {
        double total = 0;
        for (int i = 0; i < 5; i++) {
            total += marks[i];
        }
        return total;
    }

    double calculatePercentage() {
        return calculateTotal() / 5.0;
    }

    char determineGrade() {
        double percentage = calculatePercentage();
        if (percentage >= 90) return 'A';
        else if (percentage >= 75) return 'B';
        else if (percentage >= 60) return 'C';
        else if (percentage >= 40) return 'D';
        else return 'F';
    }

    void displayResult() {
        cout << "\n--- Student Result ---" << endl;
        cout << "Name       : " << name << endl;
        cout << "Roll No    : " << rollNo << endl;
        cout << "Marks      : ";
        for (int i = 0; i < 5; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;
        cout << "Total      : " << calculateTotal() << " / 500" << endl;
        cout << "Percentage : " << calculatePercentage() << "%" << endl;
        cout << "Grade      : " << determineGrade() << endl;
        cout << "----------------------" << endl;
    }
};

int main() {
    double sampleMarks[5] = {85.5, 92.0, 78.0, 88.5, 95.0};
    Student student1("Tawqeer ul Islam", 101, sampleMarks);
    student1.displayResult();
    return 0;
}
