/*
 * Sort an array in wave form
Last Updated : 12 Jun, 2024
Given an unsorted array of integers, sort the array into a wave array. An array arr[0..n-1] is sorted in wave form if:
arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..

Examples:

Input:  arr[] = {10, 5, 6, 3, 2, 20, 100, 80}
Output: arr[] = {10, 5, 6, 2, 20, 3, 100, 80}
Explanation:
here you can see {10, 5, 6, 2, 20, 3, 100, 80} first element is larger than the second and the same thing is repeated again and again. large element – small element-large element -small element and so on .it can be small element-larger element – small element-large element -small element too. all you need to maintain is the up-down fashion which represents a wave. there can be multiple answers.

Input: arr[] = {20, 10, 8, 6, 4, 2}
Output: arr[] = {20, 8, 10, 4, 6, 2} */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare (const void* a, const void* b) {
	return (*(int*) a - *(int*) b);
}

void swap (int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void print_array(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void large_small (int* a, int n) {
	qsort(a, n, sizeof(int), compare);

	print_array(a,n);

	for (int i = 1; i < n; i = i+2) {
		swap (&a[i-1], &a[i]);
	}
}

void large_small_1(int* a, int n) {
	int res[n];
        qsort(a, n, sizeof(int), compare);
        print_array(a,n);

	int j = 0;
	int start = 0;
	int end = n-1;

	while (start <= end) {
		for (int i = 0; i < n; i++) {
			res[j++] = (i % 2 == 0) ? a[end--] : a[start++];
		}
	}
	print_array(res,n);
}
		

int main () {
	int N;
	printf("Enter Array Size : ");
	scanf("%d", &N);

	int* arr = (int*) malloc (N * sizeof(int));

	for (int i = 0; i < N; i++) {
                // scanf("%d", &a[i]);
		arr[i] = rand() % 20 + 1;
        }

	print_array(arr,N);
	large_small_1(arr,N);
	//print_array(arr,N);

	free(arr);

	return 0;
}


