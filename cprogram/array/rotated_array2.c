/*
 * Maximum sum of i*arr[i] among all rotations of a given array
   Given an array arr[] of n integers, find the maximum that maximizes the sum of the value of i*arr[i] where i varies from 0 to n-1.

Examples:  

Input: arr[] = {8, 3, 1, 2}
Output: 29
Explanation: Lets look at all the rotations,
{8, 3, 1, 2} = 8*0 + 3*1 + 1*2 + 2*3 = 11
{3, 1, 2, 8} = 3*0 + 1*1 + 2*2 + 8*3 = 29
{1, 2, 8, 3} = 1*0 + 2*1 + 8*2 + 3*3 = 27
{2, 8, 3, 1} = 2*0 + 8*1 + 3*2 + 1*3 = 17

Input: arr[] = {3, 2, 1}
Output: 7
Explanation: Lets look at all the rotations,
{3, 2, 1} = 3*0 + 2*1 + 1*2 = 4
{2, 1, 3} = 2*0 + 1*1 + 3*2 = 7
{1, 3, 2} = 1*0 + 3*1 + 2*2 = 7 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int* arr,int n) {
	for (int i = 0; i< n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap (int* a, int* b) {
	int t= *a;
	*a = *b;
	*b = t;
}

int main () {
	int N;
	printf("Enter the Array Size : ");
	scanf("%d", &N);

	int* arr = (int*) malloc (N*sizeof(int));

	srand(time(NULL));
	for(int i = 0; i < N; i++) {
		arr[i] = rand() % 50 + 1;
	}

	int t = 0;
	int sum = 0;
	int r;

	while (t < N) {
		printf("%d Rotation : ", t+1);
		print_array (arr, N);
		int val = 0;
		for (int i = 0; i < N; i++) {
			val += arr[i] * i;
		}
		printf("val : %d\n",val);
		if (val > sum) {
			sum = val;
			r = t+1;
		}

		int i = 0, j = N-1;
		while (i != j){
			swap (&arr[i], &arr[j]);
			j--;
		}
		t++;
	}

	printf("Maximum sum %d in %d rotation\n", sum, r);

	free(arr);
	return 0;
}






