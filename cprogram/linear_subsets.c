#include <stdio.h>

void printSubset(int arr[], int start, int end) {
    printf("{ ");
    for (int i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}

void generateSubsets(int arr[], int n) {
    for (int i = 0; i < n; i++) {
	    for (int j = i; j < n; j++) {
		    printf("%d - %d", i, j);
		    printSubset(arr, i, j);
	    }
    }
}

int main() {
    int arr[] = {3, 7, 1, 9, 15, 14, 6, 2, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    generateSubsets(arr, n);

    return 0;
}

