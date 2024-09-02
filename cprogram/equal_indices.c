/*
 * Write a program in C to find the equilibrium index of an array.
Expected Output:
The given array is:
0 -4 7 -4 -2 6 -3 0
The equilibrium index found at : 7 5 0 */

#include <stdio.h>
#include <stdlib.h>

void print_arr(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void equal_indices1(int* a, int n) {
	printf("Equal Indices1 : ");
	for (int i = 0; i < n; i++) {
		int left = 0, right = 0;
		for (int j = i-1; j >= 0; j--) {
			left += a[j];
		}

		for (int j = i+1; j < n; j++) {
                        right += a[j];
                }

		if (left == right) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

void equal_indices2(int* a, int n) {
	int left[n], right[n];
	left[0] = 0, right[n-1] = 0;

	for (int i = 1; i < n; i++) {
		left[i] = left[i-1] + a[i-1];
	}

	for (int i = n-2; i >= 0; i--) {
                right[i] = right[i+1] + a[i+1];
        }

	printf("left : ");
	print_arr(left,n);
	printf("right : ");
	print_arr(right,n);

	printf("Equal Indices2 : ");
	for (int i = 0; i < n; i++) {
                if (left[i] == right[i]) {
			printf("%d ", i);
		}
	}
	printf("\n");
}


int main () {
	int n;
	printf("Enter Array size : ");
	scanf("%d", &n);

	int* a = (int*) malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	print_arr(a, n);

	equal_indices1(a, n);
	equal_indices2(a, n);

	free(a);

	return 0;
}


