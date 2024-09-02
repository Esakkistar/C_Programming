/*
 * First find the each element counts. Then sort the array depends on their counts in decending order.
 * If their counts are same then sort correspondig array value. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare (const void* a, const void* b) {
	return (*(int*)b - *(int*)a);
}
void swap(int* a, int* b) {
       int t = *a;
       *a = *b;
       *b = t;
}       
void sort_count (int* a, int n, int* size) {
	int cnt[256];
	memset(cnt, 0, sizeof(cnt));

	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
	}
	int k = 0;
	int num[n];

	for (int i = 0; i < n; i++) {
		if (cnt[a[i]]) {
			a[k] = a[i];
			num[k] = cnt[a[i]];
			k++;
		        cnt[a[i]] = 0;
		}
	}
	*size = k;

	for (int i = 0; i < k; i++) {
                printf("%d - %d\n", a[i], num[i]);
        }

	for (int i = 0; i < k; i++) {
		for (int j = i+1; j < k; j++) {
			if (num[i] == num[j] && a[i] < a[j]) {
				swap(&a[i], &a[j]);
			}
			if (num[i] < num[j]) {
				swap(&num[i], &num[j]);
				swap(&a[i], &a[j]);
			}
		}
	}


	//qsort(a, k, sizeof(int), compare);
}


int main () {
	int a[] = {1, 5, 8, 5, 7, 3, 1, 2, 4,5,5, 5, 1,10, 9, 6, 7, 3, 9, 10,11,1,2, 4};
	int n = sizeof(a) / sizeof(int);

	int size = 0;
	sort_count(a, n, &size);

	printf("Sort by counts : ");
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}

