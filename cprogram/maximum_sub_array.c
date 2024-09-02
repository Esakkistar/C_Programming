/*
 * Maximum Sum Subarray
Problem: Find the subarray with the maximum sum in a given array.

Example:

Input: [1, -2, 3, 4, -1, 2, 1, -5, 4]
Output: [3, 4, -1, 2, 1] (sum is 9) */

#include <stdio.h>
#include <limits.h>

// Function to find the maximum sum subarray and its indices
void maxSumSubarray(int* arr, int size) {
    int maxSum = 0; // Initialize to the smallest possible integer
    int currentSum = 0;
    int start = 0, end = 0, s = 0;

    for (int i = 0; i < size; i++) {
        currentSum += arr[i];

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = s;
            end = i;
        }

        if (currentSum < 0) {
            currentSum = 0;
            s = i + 1;
        }
    }

    printf("Maximum sum subarray: ");
    for (int i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nSum: %d\n", maxSum);
}

int main() {
    int arr[] = {1, -2, 3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    maxSumSubarray(arr, size);

    return 0;
}

