#include <stdio.h>
#include <stdlib.h>

void print_array (int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int compare( void const *a, void const* b) {
	return ( *(int*)a - *(int*) b);
}

int find_max(int* a, int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
	}
	return max;
}
void missing_element(int* a, int n) {

	//qsort(a, n, sizeof(int), compare);
	
	int max = find_max(a, n);
	//int* hash = (int*) calloc(max+1, sizeof(int));
	int* hash = (int*) malloc((max+1) * sizeof(int));
	
	for (int i = 0; i < max+1; i++) {
		hash[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		hash[a[i]] = 1;
	}
        int c = 0;
	for (int i = 0; i < max+1; i++) {
		if (hash[i]) {
			printf("%d ", i);
			a[c++] = i;
		}
	}
	printf("\n");

	printf("Sort Array : ");
	print_array(a, c);

	int j = a[0];

	printf("Missing Elements from %d to %d : ", a[0], a[c-1]);

	for (int i = 0; i < c; i++) {
		if ( j != a[i]) {
			printf("%d ", j);
		}
		j++;
	}
	printf("\n");
}

void repeating_element (int* a, int n) {
	int max = find_max(a, n);
	
	int* hash = (int*) calloc(max+1, sizeof(int));

	for (int i = 0; i < n; i++) {
		hash[a[i]]++;
	}

	printf("Repeating Elements : \n");
	for (int i = 0; i < max+1; i++) {
		if (hash[i] > 1) 
			printf("%d - %d times\n",i, hash[i]);
	}
}

int main () {
	int arr[]  = {4, 3, 6, 2, 1, 1, 10, 8};
	int n = sizeof(arr) / sizeof(arr[0]);

	repeating_element(arr, n);
	missing_element(arr, n);

	return 0;
}








		




