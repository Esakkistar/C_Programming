#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

void matrix_sum(int** mat, int r, int c) {
	int upper_sum = 0, lower_sum = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i > j) {
				lower_sum += mat[i][j];
			}
			else if (i < j) {
				upper_sum += mat[i][j];
			}
		}
	}

	printf("Sum of upper triangular matrix : %d\n", upper_sum);
	printf("Sum of lower triangular matrix : %d\n", lower_sum);
}

int main () {
        int r,c;
	printf("Enter Matrix row & column : ");
        scanf("%d%d", &r,&c);

	int** mat = (int**) malloc(r * sizeof(int*));
        if (mat == NULL) {
                printf("Memory allocation is failed\n");
                return 0;
        }

        for (int i = 0; i < r; i++) {
                mat[i] = (int*) malloc(c * sizeof(int));
        }

	for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                        //scanf("%d", &mat1[i][j]);
			mat[i][j] = rand() % 20 + 1;
                }
        }

	for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                        printf("%d ", mat[i][j]);
                }
                printf("\n");
        }

	matrix_sum(mat, r, c);

	return 0;
}

