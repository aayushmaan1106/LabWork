#include <iostream>
using namespace std;

class Area {
public:
    int calculate(int side) {
        return side * side;
    }

    int calculate(int length, int width) {
        return length * width;
    }

    double calculate(double radius) {
        return 3.14159 * radius * radius;
    }
};

int main() {
    Area a;
    cout << "Area of Square: " << a.calculate(5) << endl;
    cout << "Area of Rectangle: " << a.calculate(4, 6) << endl;
    cout << "Area of Circle: " << a.calculate(3.5) << endl;
    return 0;
}
