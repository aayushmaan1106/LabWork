#include <iostream>
using namespace std;

class Maximum {
public:
    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    int max(int a, int b, int c) {
        if (a >= b && a >= c) return a;
        if (b >= a && b >= c) return b;
        return c;
    }

    double max(double a, double b) {
        return (a > b) ? a : b;
    }
};

int main() {
    Maximum m;
    cout << "Max of 10 and 20 = " << m.max(10, 20) << endl;
    cout << "Max of 5, 8 and 3 = " << m.max(5, 8, 3) << endl;
    cout << "Max of 3.2 and 4.5 = " << m.max(3.2, 4.5) << endl;
    return 0;
}