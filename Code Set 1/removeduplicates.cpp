#include <iostream>

int removeDuplicates(int arr[], int size) {
    if (size == 0 || size == 1) {
        return size;
    }

    int uniqueCount = 0;
    for (int i = 0; i < size; ++i) {
        bool isDuplicate = false;
        for (int j = 0; j < uniqueCount; ++j) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            arr[uniqueCount] = arr[i];
            uniqueCount++;
        }
    }
    return uniqueCount;
}

int main() {
    int numbers[] = {4, 2, 4, 5, 2, 3, 1, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int newSize = removeDuplicates(numbers, size);

    for (int i = 0; i < newSize; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
