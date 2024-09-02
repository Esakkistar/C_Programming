#include <stdio.h>
#include <stdlib.h>

void printsubset(int* sub, int n) {
        printf("{ ");
        for (int i = 0; i < n; i++) {
                printf("%d ", sub[i]);
        }
        printf("}\n");
}

void subsets (int* a, int arrSize, int index, int* subset, int subsetSize) {
        if (index == arrSize ) {
		if (subsetSize == 3) {
		printf("subsetSize : %d\n", subsetSize);
		printsubset (subset, subsetSize);
		}
                return;
        }
        subset[subsetSize] = a[index];
        subsets (a, arrSize, index+1, subset, subsetSize+1);
        subsets (a, arrSize, index+1, subset, subsetSize);
}

void subset_sum (int* a, int n, int sum) {
        int total = 1 << n;
        int subset[n];

        for (int mask = 0; mask < total; mask++) {
                int index = 0, subsetsum = 0;

                for (int i = 0; i < n; i++) {
                        if ( mask & (1 << i)) {
                                subsetsum += a[i];
                                subset[index++] = a[i];
                        }
                }
                if (index == 3 && subsetsum == sum) {
                        printf("{ ");
                        for (int i = 0; i < index; i++) {
                                printf("%d ", subset[i]);
                        }
                        printf("} - %d\n", subsetsum);
                }
        }
}

int main () {
        //int arr [] = {-2, 0, 0, 1,1};
        int arr [] = {0, -1, 2, -3, 1, 2, -1};
        int n = sizeof(arr) / sizeof(arr[0]);

        int sum = 0;
        int* sub = (int*) malloc (n * sizeof(int));

        //subsets(arr, n, 0, sub, 0);
        subset_sum (arr, n, sum);

        free(sub);
}
