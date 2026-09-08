#include <iostream>

int findElement(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            std::cout << i << std::endl;
            return i;
        }
    }
    return -1;
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    findElement(numbers, size, 30);
    return 0;
}
