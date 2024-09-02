#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void quick_sort (int* arr, int low, int high) {
	if (low < high) {
		int pivot = arr[low];
		int start = low;
		int end = high;

		while (start < end) {
			while (arr[start] <= pivot)
				start++;
			while (arr[end] > pivot)
				end--;
			if (start < end) 
				swap (&arr[start], &arr[end]);
		}
		swap(&arr[low], &arr[end]);

		quick_sort(arr, low, end-1);
		quick_sort(arr, end+1, high);
	}
}

void print_array(int* arr, int n) {
	for (int i = 0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main () {
	int N;
	printf("Enter the Number :");
	scanf("%d", &N);

	int* arr = (int*) malloc (N*sizeof(int));

	printf("Fill Array: ");
	for (int i = 0; i<N; i++) {
		arr[i] = rand() % 30 + 1;
	}

	printf("Array: ");
	print_array(arr,N);

	quick_sort(arr, 0, N-1);

	printf("Sorted Array: ");
        print_array(arr,N);

	free(arr);

	return 0;
}
