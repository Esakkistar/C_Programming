#include <stdio.h>
#include <stdbool.h>

void printallpartitions (int* a, int n) {
	int total_partitions = 1 << n;

	for (int mask = 0; mask < total_partitions/2; mask++) {
		printf("Partition 1 : {");
		bool ispartition1 = true;
		
		for (int i = 0; i < n; i++) {
			if ( mask & (1 << i)) {
				if (!ispartition1)
					printf(", ");

				printf("%d", a[i]);
				ispartition1 = false;
			}
		}

		if (ispartition1)
			printf("Empty");

		printf("}\n");

		printf("Partition 2 : {");
                bool ispartition2 = true;

                for (int i = 0; i < n; i++) {
                        if ( !(mask & (1 << i)) ) {
                                if (!ispartition2)
                                        printf(", ");

                                printf("%d", a[i]);
                                ispartition2 = false;
                        }
                }

                if (ispartition2)
                        printf("Empty");

                printf("}\n\n");
	}
}

int main () {
	int arr[] = {1, 2, 3, 5, 7};
	int n = sizeof(arr) / sizeof(arr[0]);

	printallpartitions(arr, n);

	return 0;
}
