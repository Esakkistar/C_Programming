/*
 * Given a sorted array and a number x, find the pair in array whose sum is closest to x
Given a sorted array and a number x, find a pair in an array whose sum is closest to x.

Examples:

Input: arr[] = {10, 22, 28, 29, 30, 40}, x = 54
Output: 22 and 30

Input: arr[] = {1, 3, 4, 7, 10}, x = 15
Output: 4 and 10 */

#include <stdio.h>
#include <stdlib.h>

int main () {
	//int a[] = {10, 22, 28, 29, 30, 40};
	int a[] = {1, 3, 4, 7, 10};
	int n = sizeof(a) / sizeof(a[0]);
       	int x = 15;

	int sum = a[0] + a[1];

	int diff = sum > x ? sum - x : x - sum;
	int p1 = a[0], p2 = a[1];

	for (int i = 1; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			sum = a[i] + a[j];
			int diff2 = sum > x ? sum - x : x - sum;
			if (diff > diff2) {
				diff = diff2;
				p1 = a[i];
				p2 = a[j];
			}
		}
	}

	printf("closest pair of %d is : %d - %d\n", x, p1,p2);

	return 0;
}





