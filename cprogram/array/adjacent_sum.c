/*
 * Write a program in C to return the maximum sum such that no two elements are adjacent.

Expected Output :
The given array is : 1 3 5 9 7 10 1 10 100
The maximum sum from the array such that no two elements are adjacent is: 122 */

#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxNonAdjacentSum(int arr[], int n) {
    int incl = arr[0];  // Maximum sum including the previous element
    int excl = 0;       // Maximum sum excluding the previous element
    int excl_new;       // Temporary variable to store new excluding sum

    for (int i = 1; i < n; i++) {
        // Current max excluding the current element
        excl_new = max(incl, excl);

        // Current max including the current element
        incl = excl + arr[i];

        // Update excl to excl_new for the next iteration
        excl = excl_new;
    }

    // Return the maximum of incl and excl
    return max(incl, excl);
}

int main() {
    int arr[] = {1, 3, 5, 9, 20, 7, 10, 1, 10, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The given array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int max_sum = maxNonAdjacentSum(arr, n);

    printf("The maximum sum from the array such that no two elements are adjacent is: %d\n", max_sum);

    return 0;
}

