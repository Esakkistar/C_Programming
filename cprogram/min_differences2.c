/*
 * Write a program in C to find the minimum distance between two numbers in a given array.
Expected Output:
The given array is:
7 9 5 11 7 4 12 6 2 11
The minimum distance between 7 and 11 is: 1 */

#include <stdio.h>
#include <stdlib.h> 
#include <limits.h>

int main () {
	int a[] = {7, 9, 5, 11, 7, 4, 12, 6, 2, 11};
	int n = sizeof(a) / sizeof(a[0]);

	int n1 = 7, n2 = 11;
	int pos1 = INT_MAX, pos2 = INT_MAX, min = INT_MAX;

	for (int i = 0; i < n; i++) {
		if (a[i] == n1)
			pos1 = i;
		else if (a[i] == n2) 
			pos2 = i;

		if (pos1 < n && pos2 < n) {
			printf("%d - %d\n", pos1, pos2);
			int diff = abs(pos1 - pos2);
			if (diff < min){
				min = diff;
			}
		}
	}
	printf("The minimum distance between %d and %d is: %d\n", n1, n2, min);

	return 0;
}
