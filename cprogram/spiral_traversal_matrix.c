#include <stdio.h>

void spiral_traverse (int mat[10][10], int r, int c) {
	int top = 0, bottom = r-1, left = 0, right = c-1;
        printf("Spiral_Traversal_matrix : ");
	while (top <= bottom && left <= right) {

		for (int i = left; i <= right; i++) {
			printf("%d ", mat[top][i]);
		}
		top++;

		for (int i = top; i <= bottom; i++) {
			printf("%d ", mat[i][right]);
		}
		right--;
		
		if (top <= bottom) {
			for (int i = right; i >= left; i--) {
				printf("%d ", mat[bottom][i]);
			}
		}
		bottom--;

		if (left <= right) {
			for (int i = bottom; i >= top; i--) {
				printf("%d ", mat[i][left]);
			}
		}
		left++;
	}
	printf("\n");
}
	

int main () {
	int mat[10][10];
        int r,c;
        printf("Enter the row and column: ");
        scanf("%d%d", &r,&c);

        printf("Fill the Matrix Element : ");
        for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                        scanf("%d", &mat[i][j]);
                }
                printf("\n");
        }

        printf("Original Matrix : \n");
        for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                        printf("%d ", mat[i][j]);
                }
                printf("\n");
        }
        printf("\n");

	spiral_traverse(mat,r,c);

	return 0;
}


