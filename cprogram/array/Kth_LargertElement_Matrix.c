#include <stdio.h>
#include <stdlib.h>

int kth_largest_element_matrix(int**mat, int r, int c, int K) {
	int max = 0, kth_max;
        for (int k = 0; k < K; k++) {
		for (int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if(mat[i][j] > max ) {
					max = mat[i][j];
				}
			}
		}
		for (int i = 0; i < r; i++) {
                        for(int j = 0; j < c; j++) {
                                if(mat[i][j] == max ) {
                                        mat[i][j] = 0;
                                }
                        }
                }
		kth_max = max;
		max = 0;
	}
	return kth_max;
}

int kth_largest_element_matrix_array(int**mat, int r, int c, int K) {
	int arr[r*c], n = 0;
	int* hash = (int*) calloc(30, sizeof(int));

	for (int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			hash[mat[i][j]] = 1;
		}
	}

	for (int i = 0; i < 30; i++) {
		if (hash[i]) {
		      arr[n++] = i;
		}
	}

	printf("Print Array : ");
	for (int i = 0; i < n; i++ ) {
		printf ("%d ", arr[i]);
	}
	printf("\n");

	free(hash);

	return arr[n-K];
}

void printMatrix(int** mat, int r, int c) {
        for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                        printf("%d ", mat[i][j]);
                }
                printf("\n");
	}
}

void freematrix (int** mat , int r) {
	for (int i = 0; i < r; i++) {
		free(mat[i]);
	}
	free(mat);
}

int main () {
	int r,c,k;
	printf("Enter the row & column : ");
	scanf("%d%d", &r,&c);

	int** mat = (int**) malloc(r * sizeof(int*));
	if (mat == NULL) {
		printf("Memory allocation is failed\n");
		return 0;
	}

	for (int i = 0; i < r; i++) {
		mat[i] = (int*) malloc(c * sizeof(int));
	}
	
	printf("Fill the Matrix : ");
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			mat[i][j] = rand() % 20 + 1;
		}
	}

	printf("Original Matrix : \n");
	printMatrix(mat,r,c);

	printf("Enter the value of K :");
	scanf("%d",&k);
	
	//int n = kth_largest_element_matrix(mat,r,c,k);
	int n = kth_largest_element_matrix_array(mat,r,c,k);
	printf("%dth Largest Element in Matrix : %d\n",k, n);

	freematrix(mat,r);

	return 0;
}
