#include <stdio.h>
#include <stdlib.h>

int sum = 15;
// Function to print a subset
void printSubset(int* subset, int subsetSize, int** comb, int c) {
    comb[c] = (int*) malloc ((subsetSize+1) * sizeof(int));
    for (int i = 0; i < subsetSize; i++) {
	comb[c][i] = subset[i];
    }
    comb[c][subsetSize] = -1;
}

// Backtracking function to generate subsets
void generateSubsets(int* set, int setSize, int index, int* subset, int subsetSize, int** comb, int* c) {
    // Base case: if we've processed all elements
    if (index == setSize) {
        printSubset(subset, subsetSize, comb, *c);
	(*c)++;
        return;
    }

    // Include set[index] in the subset
    subset[subsetSize] = set[index];
    generateSubsets(set, setSize, index + 1, subset, subsetSize + 1, comb, c);

    // Exclude set[index] from the subset
    generateSubsets(set, setSize, index + 1, subset, subsetSize, comb, c);
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

    int total = 1 << setSize;
    int** combination = (int**) malloc (total * sizeof(int*));
    int cnt = 0;

    printf("All subsets are:\n");
    generateSubsets(set, setSize, 0, subset, 0, combination, &cnt);

    printf("cnt : %d\n", cnt);
    for (int i = 0; i < cnt; i++) {
	  //  int n = sizeof(combination[i]) / sizeof(combination[i][0]);
	    for (int j = 0; combination[i][j] != -1; j++) {
		    printf("%d ", combination[i][j]);
	    }
	    free(combination[i]);
	    printf("\n");
    }
	    

    // Free allocated memory
    free(set);
    free(subset);
    free(combination);

    return 0;
}

