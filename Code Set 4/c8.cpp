#include <iostream>
using namespace std;

class B;

class A {
    int valA;

public:
    A(int v) {
        valA = v;
    }

    friend int calculateSum(A objA, B objB);
};

class B {
    int valB;

public:
    B(int v) {
        valB = v;
    }

    friend int calculateSum(A objA, B objB);
};

int calculateSum(A objA, B objB) {
    return objA.valA + objB.valB;
}

int main() {
    A a(10);
    B b(20);
    cout << "Sum = " << calculateSum(a, b) << endl;
    return 0;
}