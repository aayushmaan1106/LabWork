#include <iostream>

using namespace std;

int main() {
    double a, b;
    char op;
    cin >> a >> op >> b;
    try {
        if (op == '/' && b == 0) {
            throw 0;
        }
        if (op != '+' && op != '-' && op != '*' && op != '/') {
            throw op;
        }
        if (op == '+') cout << a + b << endl;
        else if (op == '-') cout << a - b << endl;
        else if (op == '*') cout << a * b << endl;
        else if (op == '/') cout << a / b << endl;
    } catch (int) {
        cout << "Division by Zero Error." << endl;
    } catch (char) {
        cout << "Invalid Operator Error." << endl;
    }
    return 0;
}