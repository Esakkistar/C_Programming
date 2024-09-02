/*
 * Find Subarray with given Sum from Array of non-negative Numbers

 Given a 1-based indexing array arr[] of non-negative integers and an integer sum. You mainly need to return the left and right indexes(1-based indexing) of that subarray. In case of multiple subarrays, return the subarray indexes which come first on moving from left to right. If no such subarray exists return an array consisting of element -1.



Examples: 

Input: arr[] = { 15, 2, 4, 8, 9, 5, 10, 23}, sum = 23
Output: 2 5
Explanation: Sum of elements between indices 1 and 4 is 2 + 4 + 8 + 9 = 23

Input: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
Output: 2 5
Explanation: Sum of elements between indices 1 and 4 is 4 + 0 + 0 + 3 = 7

Input: arr[] = {1, 4}, sum = 0
Output: -1
Explanation: There is no subarray with 0 sum */

#include <stdio.h>

int main () {
	//int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23};
	int arr[] =  {1,4};
	//int arr[] = {1, 4, 0, 0, 3, 10, 5};
        int sum = 0;
	int value, x,y, flag = 0;

	int n = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < n; i++) {
		value = arr[i];
		for (int j = i+1; j < n; j++) {
			value += arr[j];
			if (value == sum) {
				x = i;
				y = j;
				flag = 1;
				break;
			}
			else if (value > sum) 
				break;
		}
		if (flag) {
			printf("Sum of elements between indices %d and %d is %d\n",x+1,y+1,sum);
			break;
		}
	}

	if (flag == 0)
		printf("Ans : -1\n");

	return 0;
} 


