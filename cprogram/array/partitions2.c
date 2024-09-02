#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void partitions (int* a, int n) {
	int total_partitions = 1 << n;
	int max = 0;

	for (int mask = 0; mask < total_partitions/2; mask++) {
		int subsetsum = 0;
		bool sub[n];

		for (int i = 0; i < n; i++) {
			sub[i] = false;
		        if (mask & (1 << i)) {
				subsetsum += a[i];
				sub[i] = true;
			}
		}
		if (subsetsum > max) {
		max = subsetsum;	

		printf("{ ");
		for (int i = 0; i < n; i++ ) {
			if (sub[i])
				printf("%d ", a[i]);
		}
		printf ("} = %d\n", subsetsum); 
		}

		/*subsetsum = 0;
		printf("{ ");
                for (int i = 0; i < n; i++ ) {
                        if (!sub[i]) {
                                printf("%d ", a[i]);
				subsetsum += a[i];
			}
                }
                printf ("} = %d\n", subsetsum);*/
	}
}

int main () {
	int n;
	printf("Enter the array size : ");
	scanf("%d", &n);

	int* arr = (int*) malloc(n * sizeof(int));

	for(int i = 0; i < n; i++) {
		//arr[i] = rand() % 10;
		scanf("%d", &arr[i]);
	}

	printf("Array : ");
	for(int i = 0; i < n; i++) {
                printf("%d ",arr[i]);
        }
	printf("\n");

	partitions(arr, n);

	return 0;
}

