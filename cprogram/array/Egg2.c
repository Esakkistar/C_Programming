#include <stdio.h>
#include <stdlib.h>

void print_array(int* arr, int N) {
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void count_group(int* arr, int N) {
	int found[N];

	for (int i = 0; i < N; i++) {
                found[i] = 1;
        }

	for (int i = 0; i < N-1; i++) {
		for(int j = i+1; j < N; j++) {
			if (arr[i] == arr[j]) {
				found[i]++;
				found[j]++;
			}
		}
	}
	print_array(found,N);

	for (int i = 0; i < N; i++) {
                arr[i] = N - found[i];
        }

}


int main () {
	int N;
	int* arr;

	printf("Enter the Number of Array Elements : ");
	scanf("%d",&N);

	arr = (int*) malloc (N * sizeof(int));

        printf ("Fill the array Elements : ");
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	print_array(arr,N);

	count_group(arr,N);

        printf ("Group Count array Elements : ");
	print_array(arr,N);

	free(arr);

	return 0;
}
