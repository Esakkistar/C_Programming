#include <stdio.h>
#include <stdlib.h>

void print_array (int* a, int n ) {
	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

void swap (int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void permutations (int* a, int start, int end) {
	if (start == end) {
		print_array (a, end+1);
	}
	else {
		for (int i = start; i <= end; i++){
			swap (&a[start], &a[i]);
			permutations (a, start+1, end);
			swap (&a[start], &a[i]);
		}
	}
}

int main () {
	int N;
	printf("Enter the array size : ");
	scanf("%d",&N);
	int* arr = (int*) malloc (N * sizeof(int));

	printf("Fill Array : ");
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}

	permutations(arr, 0, N-1);

	free(arr);

	return 0;
}




