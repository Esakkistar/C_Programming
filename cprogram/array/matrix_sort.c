#include <stdio.h>
#include <stdlib.h>

void row_sort_matrix(int** mat, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int k = 0; k < c-1; k++) {
			for (int j = k+1; j < c; j++) {
				if (mat[i][k] > mat[i][j]) {
					int t = mat[i][k];
					mat[i][k] = mat[i][j];
					mat[i][j] = t;
				}
			}
		}
	}
}

void col_sort_matrix(int** mat, int r, int c) {
        for (int j = 0; j < c; j++) {
                for (int k = 0; k < r-1; k++) {
                        for (int i = k+1; i < r; i++) {
                                if (mat[k][j] > mat[i][j]) {
                                        int t = mat[k][j]; 
                                        mat[k][j] = mat[i][j];
                                        mat[i][j] = t;
                                }
                        }
                }
        }
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
	int r,c,newRow;
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
	
	/*row_sort_matrix(mat,r,c);
	
	printf("Ascending Order Row Wise Sorted Matrix : \n");
	printMatrix(mat, r, c);*/
	
	col_sort_matrix(mat,r,c);
	printf("Ascending Order Column Wise Sorted Matrix : \n");
	printMatrix(mat, r, c);

	freematrix(mat,r);

	return 0;
}


/*
 *
 * #include <stdio.h>
#include <stdlib.h>

// Function to compare two integers (for qsort)
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to print the matrix
void printMatrix(int matrix[][4], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to sort each row of the matrix
void sortRows(int matrix[][4], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        qsort(matrix[i], cols, sizeof(int), compare);
    }
}

// Function to sort each column of the matrix
void sortColumns(int matrix[][4], int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        // Extract column into a temporary array
        int *temp = (int *)malloc(rows * sizeof(int));
        for (int i = 0; i < rows; i++) {
            temp[i] = matrix[i][j];
        }
        // Sort the temporary array
        qsort(temp, rows, sizeof(int), compare);
        // Put sorted column back into the matrix
        for (int i = 0; i < rows; i++) {
            matrix[i][j] = temp[i];
        }
        free(temp);
    }
}

int main() {
    int matrix[4][4] = {
        {10, 2, 30, 20},
        {15, 5, 35, 25},
        {20, 10, 25, 30},
        {30, 25, 35, 40}
    };

    int rows = 4;
    int cols = 4;

    printf("Original Matrix:\n");
    printMatrix(matrix, rows, cols);

    sortRows(matrix, rows, cols);
    sortColumns(matrix, rows, cols);

    printf("Sorted Matrix:\n");
    printMatrix(matrix, rows, cols);

    return 0;
}
*/
