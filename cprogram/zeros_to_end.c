
/*
 * 7. Move All Zeroes to End
Problem: Move all zeroes in the array to the end while maintaining the order of non-zero elements.

Example:

Input: [0, 1, 0, 3, 12]
Output: [1, 3, 12, 0, 0] */

#include <stdio.h>
#include <stdlib.h>

void print_array (int* a, int n) {
	printf("Array : ");
	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

void swap (int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int compare (void const* a, void const* b) {
	return ( *(int*)a - *(int*)b);
}
/*
int main () {
	int arr[] = {0, 0, 0, 0, 1, 0, 3, 4, 0, 0, 0, 0, 2, 5, 0, 12, 10, 0, 8};

	int n = sizeof(arr) / sizeof(arr[0]);

	int k = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			swap (&arr[i], &arr[k]);
			k++;
		}
	}

	print_array (arr, n);
	qsort(arr, k, sizeof(int), compare);
	print_array (arr, n);

	return 0;
}
*/
int main () {
        int arr[] = {0, -2, 4, -2, 1, -5, 3, 4, 9, -3, 1, -6, 2, 5, 6, 12, 10, -4, 8};

        int n = sizeof(arr) / sizeof(arr[0]);

        int k = 0;
        for (int i = 0; i < n; i++) {
                if (arr[i] > 0) {
                        swap (&arr[i], &arr[k]);
                        k++;
                }
        }

        print_array (arr, n);
        qsort(arr, k, sizeof(int), compare);
        print_array (arr, n);

        return 0;
}



