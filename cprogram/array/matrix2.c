#include <stdio.h>
#include <stdlib.h>

int** eliminateRows(int** mat, int r, int c, int* newRow) {
	int Row = 0;
	int mark = 0;
	
	int** resultMat = (int**) malloc (r * sizeof(int*));

	for (int i = 0; i < r; i++) {
                resultMat[i] = (int*) malloc(c * sizeof(int));
        }

	for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
			if (mat[i][j] == -1) {
				mark++;
			}
		}
		if ( mark != c ) {
			for (int j = 0; j < c; j++) {
				resultMat[Row][j] = mat[i][j];
			}
		        Row++;
		}
		mark = 0;
	}
        
	resultMat = (int**) realloc(resultMat, Row * sizeof(int*));

	*newRow = Row;
	return resultMat;
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
			scanf("%d", &mat[i][j]);
		}
	}

	printf("Original Matrix : \n");
	printMatrix(mat,r,c);
	
	int** New_mat = eliminateRows(mat,r,c,&newRow);
	
	printf("Eleminated Matrix : \n");
	printMatrix(New_mat, newRow,c);

	freematrix(mat,r);
	freematrix(New_mat,newRow);

	return 0;
}
