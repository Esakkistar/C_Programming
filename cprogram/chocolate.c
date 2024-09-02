/*
 * Chocolate Distribution Problem
Last Updated : 26 Dec, 2023
Given an array of N integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that:

Each student gets one packet.
The difference between the number of chocolates in the packet with maximum chocolates and the packet with minimum chocolates given to the students is minimum.
Examples:

Input : arr[] = {7, 3, 2, 4, 9, 12, 56} , m = 3
Output: Minimum Difference is 2
Explanation:
We have seven packets of chocolates and we need to pick three packets for 3 students
If we pick 2, 3 and 4, we get the minimum difference between maximum and minimum packet sizes.
4-2 = 2;

Input : arr[] = {3, 4, 1, 9, 56, 7, 9, 12} , m = 5
Output: Minimum Difference is 6

Input : arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50} , m = 7
Output: Minimum Difference is 10 */

/*
 *
Sort the Array.
Initialize minDifference to a large value.
Iterate over the array with a window of size m:
For each window, compute the difference between the maximum and minimum values.
Update minDifference if the current difference is smaller.
Output minDifference.*/


#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to find the minimum difference
int findMinimumDifference(int* arr, int n, int m) {
    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    printf("Array : ");
    for (int i = 0; i < n; i++) {
	    printf("%d ", arr[i]);
    }
    printf("\n");

    int minDifference = __INT_MAX__;
    
    // Find the minimum difference
    for (int i = 0; i + m - 1 < n; i++) {
        int currentDifference = arr[i + m - 1] - arr[i];
	printf("%d - %d = %d\n",arr[i + m - 1], arr[i], arr[i + m - 1] - arr[i]);
        if (currentDifference < minDifference) {
            minDifference = currentDifference;
        }
    }

    return minDifference;
}

int main() {
    int arr1[] = {7, 3, 2, 4, 9, 12, 56};
    int m1 = 3;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Minimum Difference is %d\n", findMinimumDifference(arr1, n1, m1));

    int arr2[] = {3, 4, 1, 9, 56, 7, 9, 12};
    int m2 = 5;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Minimum Difference is %d\n", findMinimumDifference(arr2, n2, m2));

    int arr3[] = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    int m3 = 7;
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Minimum Difference is %d\n", findMinimumDifference(arr3, n3, m3));

    return 0;
}

