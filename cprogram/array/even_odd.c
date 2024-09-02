#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int* arr,int n) {
	for (int i = 0; i< n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void odd_even (int* a, int n) {
	int odd[n], even[n];
	int odd_count = 0, even_count = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) 
		      even[even_count++] = a[i];
		else 
		      odd[odd_count++] = a[i];
	}
	printf("Even: ");
	print_array (even, even_count);
	printf("Odd: ");
	print_array (odd, odd_count);

	int o = 0, e = 0;

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			if (e < even_count) 
			        a[i] = even[e++];
			else
				a[i] = 0;
		}
		else {
			if (o < odd_count)
				a[i] = odd[o++];
			else
				a[i] = 0;
		}
	}

	if (even_count > odd_count) {
		for (int i = 0; i < n; i++) {
			if (a[i] == 0)
				a[i] = even[e++];
		}
	}
	else {
		for (int i = 0; i < n; i++) {
                        if (a[i] == 0)
                                a[i] = odd[o++];
                }
	}
}


int main () {
	int N;
	printf("Enter the Array Size : ");
	scanf("%d", &N);
        
	int* arr = (int*) malloc (N*sizeof(int));
        

	srand(time(NULL));
	for(int i = 0; i < N; i++) {
		arr[i] = rand() % 50 + 1;
	}

	printf("Array : ");
	print_array(arr,N);


	odd_even(arr, N);
	printf("Odd-Even Array : ");
	print_array(arr,N);

	free(arr);

	return 0;
}
