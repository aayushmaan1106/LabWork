#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    try {
        if (b == 0) {
            throw "Error: Division by zero is not allowed.";
        }
        cout << (double)a / b << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }
    return 0;
}