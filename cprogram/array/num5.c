/*
 * Given an array arr of n positive integers, your task is to find all the leaders in the array. An element of the array is considered a leader if it is greater than all the elements on its right side or if it is equal to the maximum element on its right side. The rightmost element is always a leader. 
 *
 * Examples

Input: n = 6, arr[] = {16,17,4,3,5,2}
Output: 17 5 2
Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2. */

#include <stdio.h>
#include <stdlib.h>

#define N 50
int main () {
	int arr[N];
	int n;

	printf("Enter the Number : ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 30 + 1;
	} 

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
        }
	printf("\n");

	for (int i = 0; i < n-1; i++) {
		if (arr[i] >= arr[i+1]) {
			printf("%d ", arr[i]);
		}
	}
	printf("%d\n", arr[n-1]);
	
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (arr[i] > arr[j]) {
				int t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
        printf("Ascending order : ");
	for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
        }
        printf("\n");

	return 0;

}





