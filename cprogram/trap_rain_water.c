#include<stdio.h>
#include <stdio.h>


int max (int a, int b) {
	return (a > b) ? a : b;
}

int min (int a, int b) {
	return (a < b) ? a : b;
}



int main () {
	int res = 0;
	int left, right;

	//int arr[] = {3, 0, 1, 0, 4, 0, 2};
	//int arr[] = {1, 0, 3, 0, 5};
	int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };

	int n = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < n; i++) {
		left = arr[i];
		for (int j = 0; j < i; j++) {
			left = max(left,arr[j]);
		}
		
		right = arr[i];
		for (int j = i+1; j < n; j++) {
                        right = max(right,arr[j]);
                }

		res += min(left,right) - arr[i];
	}

	printf("Total trap water : %d\n", res);

	return 0;
}
