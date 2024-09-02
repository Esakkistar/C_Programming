
/*
 * Write a C program to find all distinct triplets in a given array of integers whose sum is equal to zero. */

#include <stdio.h>
#include <stdlib.h>

// Function to sort the array
void sortArray(int arr[], int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to find all unique triplets in the array that sum to zero
void findTriplets(int arr[], int n) {
    int found = 0;

    // Sort the array
    sortArray(arr, n);

    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate elements
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = n - 1;
        int x = arr[i];

        while (left < right) {
            int sum = x + arr[left] + arr[right];
            if (sum == 0) {
                // Print the triplet
                printf("%d, %d, %d\n", x, arr[left], arr[right]);
                found = 1;

                // Move the left and right pointers to the next different elements
                while (left < right && arr[left] == arr[left + 1]) left++;
                while (left < right && arr[right] == arr[right - 1]) right--;

                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    if (!found) {
        printf("No triplets found\n");
    }
}

int main() {
    //int arr[] = {0, -1, 2, -3, 1, 2, -1};
    int arr[] = {-2, 0, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Triplets with sum zero are:\n");
    findTriplets(arr, n);

    return 0;
}

