/*
 * Find the smallest positive integer value that cannot be represented as sum of any subset of a given array
Given an array of positive numbers, find the smallest positive integer value that cannot be represented as the sum of elements of any subset of a given set. 
The expected time complexity is O(nlogn).

Examples: 

Input:  arr[] = {1, 10, 3, 11, 6, 15};
Output: 2
Input:  arr[] = {1, 1, 1, 1};
Output: 5
Input:  arr[] = {1, 1, 3, 4};
Output: 10
Input:  arr[] = {1, 2, 5, 10, 20, 40};
Output: 4
Input:  arr[] = {1, 2, 3, 4, 5, 6};
Output: 22 */

#include <stdio.h>
#include <stdlib.h>

int compare (const void* a, const void* b) {
	return ( *(int*) a - *(int*) b);
}


int main () {
	int arr[] = {1, 2, 5, 10, 20, 40};
	
	int n = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, n, sizeof(int), compare);

	for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
	}
	printf("\n");

	int res = 1;

	for (int i = 0; i < n && arr[i] <= res; i++) {
		res += arr[i];
	}
	printf("%d\n", res);
}



