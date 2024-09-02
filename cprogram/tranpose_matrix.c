#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	int mat[10][10];
	int r,c;
	printf("Enter the row and column: ");
	scanf("%d%d", &r,&c);

	printf("Fill the Matrix Element : ");
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			//scanf("%d", &mat[i][j]);
			mat[i][j] = rand() % 30;
		}
	}

	printf("Original Matrix : \n");
        for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                        printf("%d ", mat[i][j]);
                }
		printf("\n");
        }
	
	printf("Transpose Matrix : \n");
        for (int i = 0; i < c; i++) {
                for (int j = 0; j < r; j++) {
                        printf("%d ", mat[j][i]);
                }
		printf("\n");
        }
	
	printf("90 Degree clockwise direction Rotational Matrix : \n");
        for (int j = 0; j < c; j++) {
                for (int i = r-1; i >= 0; i--) {
                        printf("%d ", mat[i][j]);
                }
		printf("\n");
        }

	printf("90 Degree counter clockwise direction Rotational Matrix : \n");
        for (int j = c-1; j >= 0; j--) {
		for (int i = 0; i < r; i++) {
                        printf("%d ", mat[i][j]);
                }
                printf("\n");
        }

	return 0;
}



