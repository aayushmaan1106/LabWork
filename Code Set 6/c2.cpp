#include <iostream>
#include <cmath>

using namespace std;

class NegativeNumberException {
public:
    string what() const {
        return "Error: Square root of a negative number cannot be calculated.";
    }
};

int main() {
    double num;
    cin >> num;
    try {
        if (num < 0) {
            throw NegativeNumberException();
        }
        cout << sqrt(num) << endl;
    } catch (NegativeNumberException& e) {
        cout << e.what() << endl;
    }
    return 0;
}