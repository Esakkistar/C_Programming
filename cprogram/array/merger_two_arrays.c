#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void fill_array(int* a, int n) {
	for(int i = 0; i < n; i++) {
		a[i] = rand() % 100 + 1;
	}
}

void print_array(int* a, int n) {
	for(int i = 0; i < n; i++) {
                printf("%d ", a[i]);
        }
	printf("\n");
}

void merge_array1 (int* m, int* a1, int* a2, int n1, int n2) {
	int k = 0;
	for(int i = 0; i < n1; i++) {
                m[k] = a1[i];
		k++;
        }
	
	for(int i = 0; i < n2; i++) {
                m[k] = a2[i];
		k++;
        }
}

int* merge_array2 (int* a1, int* a2, int n1, int n2) {
        
        int* merge_arr = NULL;
	merge_arr = (int*) realloc(merge_arr, n1*n2*sizeof(int)); // (or) merge_arr = (int*) malloc(n1*n2*sizeof(int));
	merge_arr = a1;
        int k = n1;
	for(int i = 0; i < n2; i++) {
                merge_arr[k] = a2[i];
                k++;
        }
	return merge_arr;
}

void sort_array(int* s,int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if(s[i] > s[j]) {
				int t = s[i];
				s[i] = s[j];
				s[j] = t;
			}
		}
	}
}

void remove_duplicate(int* d, int n, int* new) {
	int f[n];
	int k = 0;
	
	for (int i = 0; i < n; i++) {
		f[i] = 0; 
	}

	for (int i = 0; i < n-1; i++) {
                for (int j = i+1; j < n; j++) {
                        if(d[i] == d[j]) {
				f[j] = 1;
			}
		}
		if ( f[i] == 0 ) {
                        d[k++] = d[i];
		}

	}
	if ( f[n-1] == 0 ) {
		d[k++] = d[n-1];
	}
	*new = k;

                        
       /* int j = 0;
	for (int i = 0; i < n; i++) {
		if ( f[i] == 0 ) {
			d[j] = d[i];
			j++;
		}
	}*/
}
		       	

int main () {
	int arr1[MAX];
	int arr2[MAX];
	int merge_arr[MAX];

	int n1,n2,n3;

	printf("Enter No.of Array1 Elements: ");
	scanf("%d", &n1);
	printf("Enter No.of Array2 Elements: ");
	scanf("%d", &n2);
        
//	printf("Fill Array1 : ");
	fill_array(arr1,n1);
//	printf("Fill Array2 : ");
	fill_array(arr2,n2);

	printf("Array1 : ");
	print_array(arr1,n1);
	printf("Array2 : ");
	print_array(arr2,n2);
	
	printf("Merge1 : ");
	merge_array1(merge_arr,arr1,arr2,n1,n2);
	print_array(merge_arr,n1+n2);

	printf("Merge2 : ");
	int* merge_ar = merge_array2(arr1,arr2,n1,n2);
	print_array(merge_ar,n1+n2);
	
	printf("Sorted Array : ");
	sort_array(merge_ar,n1+n2);
	print_array(merge_ar,n1+n2);
	
	printf("Duplicate Remove Sorted Array : ");
	remove_duplicate(merge_ar,n1+n2,&n3);
	print_array(merge_ar,n3);

	//free(merge_ar);


	return 0;
}
