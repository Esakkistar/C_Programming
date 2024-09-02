#include <stdio.h>
#include <stdlib.h>

int sum = 15;
// Function to print a subset
void printSubset(int* subset, int subsetSize) {
    int s = 0;
    for (int i = 0; i < subsetSize; i++) {
        s += subset[i];
    }
    if (s == sum) {
     printf("{ ");
    for (int i = 0; i < subsetSize; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
    }
}

// Backtracking function to generate subsets
void generateSubsets(int* set, int setSize, int index, int* subset, int subsetSize) {
    // Base case: if we've processed all elements
    if (index == setSize) {
        printSubset(subset, subsetSize);
        return;
    }

    // Include set[index] in the subset
    subset[subsetSize] = set[index];
    generateSubsets(set, setSize, index + 1, subset, subsetSize + 1);

    // Exclude set[index] from the subset
    generateSubsets(set, setSize, index + 1, subset, subsetSize);
}

int main() {
    int setSize;

    // Get the size of the set from the user
    printf("Enter the number of elements in the set: ");
    scanf("%d", &setSize);

    int* set = (int*) malloc(setSize * sizeof(int));
    int* subset = (int*) malloc(setSize * sizeof(int));

    // Get the elements of the set from the user
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < setSize; i++) {
        scanf("%d", &set[i]);
    }

    printf("All subsets are:\n");
    generateSubsets(set, setSize, 0, subset, 0);

    // Free allocated memory
    free(set);
    free(subset);

    return 0;
}

