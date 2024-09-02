/*
 * Count all combinations of coins to make a given value sum (Coin Change II)
Given an integer array of coins[ ] of size N representing different types of denominations and an integer sum, the task is to count all combinations of coins to make a given value sum.

Note: Assume that you have an infinite supply of each type of coin.

Examples:

Input: sum = 4, coins[] = {1,2,3}
Output: 4
Explanation: there are four solutions: {1, 1, 1, 1}, {1, 1, 2}, {2, 2}, {1, 3}

Input: sum = 10, coins[] = {2, 5, 3, 6}
Output: 5
Explanation: There are five solutions:
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5} */


#include <stdio.h>
#include <stdlib.h>

// Utility function to print combinations
void printCombinationsUtil(int* arr, int arrSize, int target, int* combination, int combinationSize, int start) {
    // Base case: if the target is zero, print the combination
    if (target == 0) {
        printf("{ ");
        for (int i = 0; i < combinationSize; i++) {
            printf("%d ", combination[i]);
        }
        printf("}\n");
        return;
    }

    // If the target is less than zero, no need to continue
    if (target < 0) {
        return;
    }

    // Try each element in the array starting from the 'start' index
    for (int i = start; i < arrSize; i++) {
        // Include arr[i] in the combination
        combination[combinationSize] = arr[i];
        // Recur with the updated target, the same index 'i' to allow repeated elements
        printCombinationsUtil(arr, arrSize, target - arr[i], combination, combinationSize + 1, i);
    }
}

// Function to print all combinations of coins that sum up to a given value
void printCombinations(int* arr, int arrSize, int target) {
    int* combination = (int*)malloc(target * sizeof(int));
    printCombinationsUtil(arr, arrSize, target, combination, 0, 0);
    free(combination);
}

int main() {
    int arr[] = {1, 4, 5, 2}; // Example elements
    int target = 13; // Target sum

    printf("All possible combinations to make sum %d:\n", target);
    printCombinations(arr, sizeof(arr) / sizeof(arr[0]), target);

    return 0;
}


/*
 *
 * #include <stdio.h>

void printCombinationsUtil(int* arr, int arrSize, int target, int* combination, int combinationSize) {
    // Base case: if the target is zero, print the combination
    if (target == 0) {
        printf("{ ");
        for (int i = 0; i < combinationSize; i++) {
            printf("%d ", combination[i]);
        }
        printf("}\n");
        return;
    }

    // If the target is less than zero, no need to continue
    if (target < 0) {
        return;
    }

    // Try each element in the array
    for (int i = 0; i < arrSize; i++) {
        // Include arr[i] in the combination
        combination[combinationSize] = arr[i];
        // Recur with the updated target and the same index (i) to allow repeated elements
        printCombinationsUtil(arr, arrSize, target - arr[i], combination, combinationSize + 1);
    }
}

void printCombinations(int* arr, int arrSize, int target) {
    int* combination = (int*)malloc(target * sizeof(int));
    printCombinationsUtil(arr, arrSize, target, combination, 0);
    free(combination);
}

int main() {
    int arr[] = {1, 2, 3}; // Example elements
    int target = 4; // Target sum

    printf("All possible combinations to make sum %d:\n", target);
    printCombinations(arr, sizeof(arr) / sizeof(arr[0]), target);

    return 0;
}
*/
