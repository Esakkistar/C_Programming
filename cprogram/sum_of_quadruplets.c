/*
 *  Write a C program to find all distinct quadruplets in a given array of integers whose sum is equal to zero. */

#include <stdio.h>
#include <stdlib.h>

int compare (const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void find_quadruplets(int a[], int n) {

	int found = 1;
	qsort(a, n, sizeof(int), compare);

	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	for (int i = 0; i < n-3; i++) {
		
		if(i > 0 && a[i] == a[i-1]) continue;

		for (int j = i+1; j < n-2; j++) {
			if (j > i+1 && a[j] == a[j-1]) continue;

			int left = j+1;
			int right = n-1;

			while (left < right) {
				int sum = a[i] + a[j] + a[left] + a[right];
				if (sum == 12) {
					printf("{ %d, %d, %d, %d }\n", a[i], a[j], a[left], a[right]);
					found = 0;

					while(left < right && a[left] == a[left+1]) left++;
					while(left < right && a[right] == a[right-1]) right--;

					left++;
					right--;
				}
				else if (sum < 0) {
					left++;
				}
				else {
					right--;
				}
			}
		}
	}
	if (found) {
		printf("Not found Quadruplets\n");
	}
}



int main () {
	int a[] = {0, 4, 7, 0, 1, 6, 6, -3};
	int n = sizeof(a) / sizeof(int);

	find_quadruplets(a, n);

	return 0;
}
