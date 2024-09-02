#include <stdio.h>
#include <stdlib.h>

void printsubset(int* sub, int n) {
        printf("{ ");
        for (int i = 0; i < n; i++) {
                printf("%d ", sub[i]);
        }
        printf("}\n");
}

void subsets (int* a, int arrSize, int index, int* subset, int subsetSize, int sum) {
	if (sum == 0 && subsetSize == 3) {
		printf("{ ");
        	for (int i = 0; i < subsetSize; i++) {
                    printf("%d ", subset[i]);
		}
        	printf("}\n");
		return;
	}

        if (index == arrSize ) {
                return;
        }
        subset[subsetSize] = a[index];
        subsets (a, arrSize, index+1, subset, subsetSize+1, sum+a[index]);
        subsets (a, arrSize, index+1, subset, subsetSize, sum);
}

int main () {
        int arr [] = {-2, 0, 0, 1,1};
        //int arr [] = {0, -1, 2, -3, 1, 2, -1};
        int n = sizeof(arr) / sizeof(arr[0]);

        int sum = 0;
        int* sub = (int*) malloc (n * sizeof(int));

        subsets(arr, n, 0, sub, 0, 0);

        free(sub);
}
