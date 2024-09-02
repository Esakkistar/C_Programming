#include <stdio.h>

// Function to find the union of two sorted arrays
void findUnion(int arr1[], int size1, int arr2[], int size2) {
    int i = 0, j = 0;

    printf("Union: ");
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            printf("%d ", arr1[i++]);
        } else if (arr1[i] > arr2[j]) {
            printf("%d ", arr2[j++]);
        } else {
            printf("%d ", arr1[i]);
            i++;
            j++;
        }
    }

    // Print remaining elements of arr1
    while (i < size1) {
        printf("%d ", arr1[i++]);
    }

    // Print remaining elements of arr2
    while (j < size2) {
        printf("%d ", arr2[j++]);
    }

    printf("\n");
}

// Function to find the intersection of two sorted arrays
void findIntersection(int arr1[], int size1, int arr2[], int size2) {
    int i = 0, j = 0;

    printf("Intersection: ");
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else {
            printf("%d ", arr1[i]);
            i++;
            j++;
        }
    }

    printf("\n");
}

int main() {
    // Example sorted arrays
    int arr1[] = {1, 2, 4, 5, 6, 6, 7};
    int arr2[] = {2, 2, 3, 5, 7, 7};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // Find and print union and intersection
    findUnion(arr1, size1, arr2, size2);
    findIntersection(arr1, size1, arr2, size2);

    return 0;
}

