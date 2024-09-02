#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);  // *(a+i)
	}
	printf("\n");
}

int* merge_array(int* a1, int* a2, int n1, int n2 ) {
	int* marr = (int*) malloc((n1+n2) * sizeof(int));

	int k = 0;

	for (int i = 0; i < n1; i++) {
                marr[k++] = a1[i];
        }

	for (int i = 0; i < n2; i++) {
		marr[k++] = a2[i];
	}

	return marr;
}

void swap (int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void sort_array (int* a, int low, int high) {
	if (low < high) {
		int pivot = a[low];
		int start = low;
		int end = high;

		while (start < end) {
		       while (a[start] <= pivot)
			       start++;
		       while (a[end] > pivot)
			       end--;
		       if (start < end) 
			       swap(&a[start], &a[end]);
		}
		swap (&a[low], &a[end]);

		sort_array (a, low, end-1);
		sort_array (a, end+1, high);
	}
}

void union_interset(int* a, int n) {
	int f[n], common[n], flag = 0, k = 0, l = 0;
	for (int i = 0; i<n; i++) {
		f[i] = 0;
	}

	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[i] == a[j]) {
				flag = 1;
				f[j] = 1;
			}
		}
		if (flag == 0) 
		       a[k++] = a[i];
		else if (f[i] == 0)
			common[l++] = a[i];

		flag = 0;
	}
	if (f[n-1] == 0) 
		a[k++] = a[n-1];

	printf("Dulicate Remove array : ");
	print_array(a, k);
	
	printf("Duplicate Elements in array : ");
	print_array(common, l);
}

void find_common(int* a1, int* a2, int n1, int n2) {
	int n = (n1+n2)/2;
	int f[n], l = 0, flag = 0;

	for (int i = 0; i < n1; i++) {
		for (int k = 0; k < l; k++ ) {
			if (a1[i] == f[k])
				flag = 1;
				break;
		}
		if (flag == 0) {
			for (int j = 0; j < n2; j++) {
				if (a1[i] == a2[j]) {
					f[l++] = a1[i];
					break;
				}
			}
		}
		flag = 0;
	}
	printf("Common Elements in arrays : ");
	for (int i = 0; i<l; i++) {
                printf("%d ", f[i]);
        }
	printf("\n");
}


int main () {
	int N1, N2;


	printf("Enter No.of Array1 Elements: ");
	scanf("%d", &N1);
	printf("Enter No.of Array2 Elements: ");
	scanf("%d", &N2);

	//srand(time(NULL));
	int* a1 = (int*) malloc (N1*sizeof(int));

	for(int i = 0; i < N1; i++) {
		a1[i] = rand() % 100 + 1;
	}

	int* a2 = (int*) malloc (N2*sizeof(int));

        for(int i = 0; i < N2; i++) {
                a2[i] = rand() % 100 + 1;
        }

	printf("Array1: ");
	print_array(a1,N1);
	printf("Array2: ");
	print_array(a2,N2);
        
	
	int* Marr = merge_array(a1,a2,N1,N2);
	printf("Merge Array: ");
	print_array(Marr,N1+N2);

	sort_array(Marr,0, N1+N2-1);
	printf("sort Array: ");
	print_array(Marr,N1+N2);
	
	union_interset(Marr, N1+N2);
	
	find_common(a1,a2,N1,N2);
	

	free(a1);
	free(a2);
	free(Marr);
	
	return 0;
}
	


