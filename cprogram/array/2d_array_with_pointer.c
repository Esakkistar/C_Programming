#include <stdio.h>

int main() {
    // Declare a 2D array of integers
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Pointer to the beginning of the array
    int (*ptr)[4] = arr; // Pointer to an array of 4 integers (each row in arr)

    // Method 1: Access elements using *(ptr + i) notation
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("Element at arr[%d][%d]: %d\n", i, j, *(*(ptr + i) + j));
        }
    }

    // Method 2: Access elements using ptr[i][j] notation
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("Element at arr[%d][%d]: %d\n", i, j, ptr[i][j]);
        }
    }

    // Method 3: Access elements using (*(ptr + i))[j] notation
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("Element at arr[%d][%d]: %d\n", i, j, (*(ptr + i))[j]);
        }
    }

    // Method 4: Access elements using *(arr[i] + j) notation
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("Element at arr[%d][%d]: %d\n", i, j, *(arr[i] + j));
        }
    }

    return 0;
}

