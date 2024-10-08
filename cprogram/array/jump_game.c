/*
 * Minimum number of jumps to reach end (Jump Game)
Last Updated : 11 Jun, 2024
Given an array arr[] where each element represents the max number of steps that can be made forward from that index. The task is to find the minimum number of jumps to reach the end of the array starting from index 0.

Examples:

Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 (1-> 3 -> 9 -> 9)
Explanation: Jump from 1st element to 2nd element as there is only 1 step.
Now there are three options 5, 8 or 9. If 8 or 9 is chosen then the end node 9 can be reached. So 3 jumps are made.

Input:  arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
Output: 10
Explanation: In every step a jump is needed so the count of jumps is 10. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int* arr,int n) {
	for (int i = 0; i< n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main () {
	int N;
	printf("Enter the Array Size : ");
	scanf("%d", &N);

	int* arr = (int*) malloc (N*sizeof(int));

	srand(time(NULL));
	for(int i = 0; i < N; i++) {
		//arr[i] = rand() % 10 + 1;
		scanf("%d", &arr[i]);
	}

	print_array(arr,N);

	int cnt = 0;
	int t = 0;
	while (t < N-1) {
		t += arr[t];
		cnt++;
	}


	printf("Minimun Jumps : %d\n", cnt);

	free (arr);

	return 0;
}

