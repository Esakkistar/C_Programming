/*
 * Write a program in C to count all possible paths from top left to bottom right of a m X n matrix.
Expected Output:
The size of matrix is : 4 x 4
The all possible paths from top left to bottom right is: 20 */

#include <stdio.h>
#include <stdlib.h>

void matrix_multipliation_table (int** a, int r, int c) {
        int n = 1;
        for (int i = 0; i < r; i++) {
                a[i][0] = n++;
        }
        n = 1;
        for (int j = 0; j < c; j++) {
                a[0][j] = n++;
        }
	int k = 0;
        for (int i = 1; i < r; i++) {
                for (int j = 1; j < c; j++) {
                        a[i][j] = a[i][k] * a[k][j];
                }
        }
	printf("Multi Table Array : \n");
        for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                        printf("%d ", a[i][j]);
                }
                printf("\n");
        }
}

int pathcount(int** a, int r, int c) {
	for (int i = 0; i < r; i++) {
		a[i][0] = 1;
	}
	for (int j = 0; j < c; j++) {
                a[0][j] = 1;
        }
	for (int i = 1; i < r; i++) {
                for (int j = 1; j < c; j++) {
                        a[i][j] = a[i-1][j] + a[i][j-1];
                }
	}

	return a[r-1][c-1];
}

	
int main () {
	int r, c;
	printf("Enter the row : ");
	scanf("%d", &r);
	printf("Enter the column :");
	scanf("%d", &c);

	int** a = (int**) malloc(r * sizeof(int*));

	for (int i = 0; i < r; i++) {
		a[i] = (int*) malloc (c * sizeof(int));
	}

	int cnt = pathcount(a, r, c);

	printf("Array : \n");
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("The all possible paths from top left to bottom right is : %d\n", cnt);

	matrix_multipliation_table(a, r, c);

	free(a);

	return 0;
}


