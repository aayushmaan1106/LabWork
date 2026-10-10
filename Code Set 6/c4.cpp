#include <iostream>

using namespace std;

int main() {
    int marks;
    cin >> marks;
    try {
        if (marks < 0 || marks > 100) {
            throw "Invalid Marks! Marks should be between 0 and 100.";
        }
        cout << "Marks: " << marks << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }
    return 0;
}