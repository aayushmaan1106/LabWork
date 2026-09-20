#include <iostream>
using namespace std;

class Numbers {
    int num1;
    int num2;

public:
    Numbers(int a, int b) {
        num1 = a;
        num2 = b;
    }

    friend void findLargest(Numbers n);
};

void findLargest(Numbers n) {
    if (n.num1 > n.num2) {
        cout << "Largest = " << n.num1 << endl;
    } else {
        cout << "Largest = " << n.num2 << endl;
    }
}

int main() {
    Numbers obj(25, 40);
    findLargest(obj);
    return 0;
}