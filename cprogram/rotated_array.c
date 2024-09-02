/*
 * Given an array, the task is to cyclically rotate the array clockwise by one time. 

Examples:  

Input: arr[] = {1, 2, 3, 4, 5}
Output: arr[] = {5, 1, 2, 3, 4}

Input: arr[] = {2, 3, 4, 5, 1}
Output: {1, 2, 3, 4, 5} */

#include <stdio.h>

void swap (int* a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void rotate(int arr[], int n)
{
    // store the last element in a variable
    int last_el = arr[n - 1];
    for (int i = n - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    // assign the last element to first element
    arr[0] = last_el;
}

void rotate2 (int a[], int n) {
	int i = 0, j = n-1;
	while (i != j) {
		swap (&a[i], &a[j]);
		i++;
	}
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5 }, i;
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Function Call
    rotate(arr, n);

    printf("\nRotated array is\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    rotate2(arr, n);

    printf("\nRotated2 array is\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
