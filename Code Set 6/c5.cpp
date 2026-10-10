#include <iostream>

using namespace std;

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int index;
    cin >> index;
    try {
        if (index < 0 || index > 9) {
            throw "Error: Array Index Out of Bounds.";
        }
        cout << "Element: " << arr[index] << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }
    return 0;
}