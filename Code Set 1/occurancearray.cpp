#include <iostream>

int countOccurrences(int arr[], int size, int target) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    int numbers[] = {4, 2, 5, 2, 8, 2, 3};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int target = 2;

    int result = countOccurrences(numbers, size, target);

    std::cout << "The element " << target << " appears " << result << " times." << std::endl;

    return 0;
}
