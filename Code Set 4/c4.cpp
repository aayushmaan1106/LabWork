#include <iostream>
using namespace std;

class Distance {
    int feet;
    int inches;

public:
    Distance(int f = 0, int i = 0) {
        feet = f;
        inches = i;
    }

    Distance operator+(Distance const &d) {
        Distance res;
        res.feet = feet + d.feet;
        res.inches = inches + d.inches;
        if (res.inches >= 12) {
            res.feet += res.inches / 12;
            res.inches = res.inches % 12;
        }
        return res;
    }

    void display() {
        cout << feet << " ft " << inches << " in" << endl;
    }
};

int main() {
    Distance d1(5, 8), d2(3, 9);
    Distance d3 = d1 + d2;
    d3.display();
    return 0;
}