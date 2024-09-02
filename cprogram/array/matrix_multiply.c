#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int main () {
	int r1,c1,r2,c2;
	int mat1[MAX][MAX];
	int mat2[MAX][MAX];
	int multiply[MAX][MAX];

	printf("Enter 1st Matrix row & column : ");
	scanf("%d%d", &r1,&c1);
	
	printf("Enter 2nd Matrix row & column : ");
	scanf("%d%d", &r2,&c2);

	if (c1 != r2 ) {
		printf("Can't Multiply Matrixes \n");
		return 0;
	}

	printf("Enter 1st Matrix Elements : \n");
	for (int i = 0; i < r1; i++) {
		for (int j = 0; j < c1; j++) {
			scanf("%d", &mat1[i][j]);
		}
	}
	
	printf("Enter 2nd Matrix Elements : \n");
	for (int i = 0; i < r2; i++) {
		for (int j = 0; j < c2; j++) {
			scanf("%d", &mat2[i][j]);
		}
	}

	printf("Display 1st Matrix Elements : \n");
	for (int i = 0; i < r1; i++) {
		for (int j = 0; j < c1; j++) {
			printf("%d ", mat1[i][j]);
		}
		printf("\n");
	}
	printf("Display 2nd Matrix Elements : \n");
	for (int i = 0; i < r2; i++) {
		for (int j = 0; j < c2; j++) {
			printf("%d ", mat2[i][j]);
		}
		printf("\n");
	}

	printf("Matrix Multiplications : \n");
        for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c2; j++) {
                        multiply[i][j] = 0 ;
                }
        }

        for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c2; j++) {
			for (int k = 0; k < c1; k++) {
				multiply[i][j] += mat1[i][k] * mat2[k][j];
			}
		}

        }

        for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c2; j++) {
                        printf("%d ", multiply[i][j]);
                }
		printf("\n");
        }

	return 0;
}

