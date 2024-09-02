/*
 * Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears strictly more than N/2 times in the array.
 *
 * Example 1:

Input:
N = 3
A[] = {1,2,3}
Output:
-1
Explanation:
Since, each element in
{1,2,3} appears only once so there
is no majority element.
Example 2:

Input:
N = 5
A[] = {3,1,3,3,2}
Output:
3
Explanation:
Since, 3 is present more
than N/2 times, so it is
the majority element. */


#include <stdio.h>
#include <stdlib.h>

void print_array(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void majority (int* arr, int n, int* newsize) {
	int count[n], cnt;

	for (int i = 0; i < n; i++) {
                 count[i] = 0;
        }

	for (int i = 0; i < n-1; i++) {
		cnt = 1;
		for (int j = i+1; j < n; j++) {
			if (arr[i] == arr[j]) {
				count[j] = 1;
				cnt++;
			}
		}
		if (count[i] == 0) {
			count[i] = cnt;
		}
	}
	//print_array(count,n);
        cnt = 0;
	for (int i = 0; i < n; i++) {
		if (count[i] >= n/2) {
			arr[cnt++] = arr[i];
		}
	}

	arr = (int*) realloc(arr, cnt*sizeof(int));

	*newsize = cnt;
}

int main () {
	int n;
	int newsize;
	
	printf("Enter the Number : ");
	scanf("%d", &n);

	int* arr = (int*) malloc (n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	print_array(arr,n);

	majority(arr,n, &newsize);
        
	if (newsize <= 0) {
		printf("Majority Elements in Array : -1");
		return 0;
	}

	printf("Majority Elements in Array : ");
	print_array(arr, newsize);

	return 0;
}




