#include <iostream>
using namespace std;

class Interest {
    double P;
    double R;
    double T;

public:
    Interest(double p, double r, double t) {
        P = p;
        R = r;
        T = t;
    }

    inline double calculateSI() {
        return (P * R * T) / 100;
    }
};

int main() {
    Interest i(10000, 5, 2);
    cout << "SI = " << i.calculateSI() << endl;
    return 0;
}