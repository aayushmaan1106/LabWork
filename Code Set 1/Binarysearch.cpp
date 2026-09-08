#include <iostream>

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int numbers[] = {11, 22, 33, 44, 55, 66, 77};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int target = 44;

    int index = binarySearch(numbers, size, target);

    if (index != -1) {
        std::cout << "Element found at index: " << index << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}
