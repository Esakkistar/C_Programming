/*
 * Triplet Sum in Array (3sum)
Last Updated : 17 Oct, 2023
Given an array arr[] of size n and an integer X. Find if there’s a triplet in the array which sums up to the given integer X.

Examples:

Input: array = {12, 3, 4, 1, 6, 9}, sum = 24;
Output: 12, 3, 9
Explanation: There is a triplet (12, 3 and 9) present
in the array whose sum is 24.

Input: array = {1, 2, 3, 4, 5}, sum = 9
Output: 5, 3, 1
Explanation: There is a triplet (5, 3 and 1) present
in the array whose sum is 9.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int* arr,int n) {
	for (int i = 0; i< n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int triplet_sum (int* a, int n, int sum) {
	for(int i = 0; i < n-2; i++) {
		for (int j = i+1; j < n-1; j++) {
			for (int k = j+1; k < n; k++) {
				if (a[i] + a[j] + a[k] == sum) {
					printf("Triplets :  %d+%d+%d = %d\n",a[i], a[j], a[k], sum);
					return 1;
				}
			}
		}
	}
	return 0;
}

int main () {
	int N;
	printf("Enter the Array Size : ");
	scanf("%d", &N);

	int sum = 9;

	int* a = (int*) malloc (N*sizeof(int));

	srand(time(NULL));
	for(int i = 0; i < N; i++) {
		//a[i] = rand() % 15 + 1;
		scanf("%d", &a[i]);
	}

	print_array(a,N);
	int n = triplet_sum(a,N,sum);

	if (!n) 
	     printf("No elements is not equal to sum\n");

	free(a);

	return 0;
}
