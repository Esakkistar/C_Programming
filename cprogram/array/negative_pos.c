/*
 * Move all negative numbers to beginning and positive to end with constant extra space
Last Updated : 29 Apr, 2024
An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.

Examples :

Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5

Note: Order of elements is not important here. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int* arr,int n) {
	for (int i = 0; i< n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void neg_pos(int* a, int n) {
	int res[n];
	int cnt = 0;
	int start= 0;
	int end = n-1;
	int neg[n];
	int pos[n];
	int k = 0, l = 0;

	for (int i = 0; i < n; i++) {
                if (a[i] < 0) 
                        neg[k++] = a[i];
		else
			pos[l++] = a[i];
        }

	printf("Negative : ");
	print_array(neg, k);
	printf("Positive : ");
	print_array(pos, l);


	/*for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			res[cnt++] = a[i];
		}
	}
	for (int i = 0; i < n; i++) {
                if (a[i] > 0) {
                        res[cnt++] = a[i];
                }
        }*/

        while (start <= end ) {
        	for (int i = 0; i < n; i++) {
			if (a[i] < 0) 
				res[start++] = a[i];
			else 
				res[end--] = a[i];
		}
	}

	for (int i = 0; i < n; i++) {
                   a[i] = res[i];
        }
}


void alternative_pos_neg(int* a, int n) {
	int new_arr[n];

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			if (a[i] >= 0) {
				for (int j = i+1; j < n; j++) {
					if (a[j] < 0) {
						new_arr[i] = a[j];
					        break;
					}
				}
			}
			else {
			    new_arr[i] = a[i];
			}
		}
	        else {
			if (a[i] < 0) {
                                for (int j = i+1; j < n; j++) {
                                        if (a[j] > 0) {
                                                new_arr[i] = a[j];
                                                break;
                                        }
                                }
                        }
                        else {
                            new_arr[i] = a[i];
                        }
		}
	}

	print_array(new_arr,n);
}

void swap (int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void neg_pos2(int* a, int n) {
	int k = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] >= 0) {
			swap (&a[i], &a[k]);
			k++;
		}
	}
}

void alternative_pos_neg2 (int* a, int n) {
	for (int i = 0; i < n; i++) {
                if ( (i % 2 == 0) && a[i] < 0 ) {
			for (int j = i+1; j < n; j++) {
				if (a[j] >= 0) {
					swap (&a[i], &a[j]);
					break;
				}
			}
		}
		else if (i % 2 != 0 && a[i] >= 0) {
			for (int j = i+1; j < n; j++) {
                                if (a[j] < 0) {
                                        swap (&a[i], &a[j]);
                                        break;
                                }
                        }
		}
	}
}

int compare (void const* a, void const* b) {
	return ( *(int*)a - *(int*)b );
}

int main () {
	int N;
	int a[] = {-12, -10, -2, 20, -4, 11, -13, -5, 6, -7, 5, 3, -6};
	//int a[] = {20, 11, 6, 5, 3, -10, -13, -5, -2, -7, -12, -4, -6};
        N = sizeof(a) / sizeof(a[0]);
     
     /* printf("Enter the Array Size : ");
	scanf("%d", &N);

	int* a = (int*) malloc (N*sizeof(int));

	srand(time(NULL));
	for(int i = 0; i < N; i++) {
		a[i] = rand() % 15 + 1;
		//scanf("%d", &a[i]);
	}*/
	//qsort(a, N, sizeof(int), compare);
	//print_array(a,N);

	neg_pos2(a, N);
	print_array(a,N);

	alternative_pos_neg2(a, N);
	//neg_pos(a,N);
	print_array(a,N);

	return 0;
}
