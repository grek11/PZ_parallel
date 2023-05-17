#include <iostream>
#include <vector>
#include <algorithm>
#include <omp.h>

void parallel_selection_sort(std::vector<int>& arr) {
    int n = arr.size();

#pragma omp parallel for
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
        }
    }
}

int main() {
    const int n = 10;
    std::vector<int> arr = { 9, 3, 7, 1, 5, 8, 2, 6, 4, 0 };

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Використання 4 потоків
    omp_set_num_threads(4);

    // Сортування методом вибору з паралелізацією
    parallel_selection_sort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
