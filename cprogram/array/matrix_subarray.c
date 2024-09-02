/*
 * Write a program in C to find the largest square sub-matrix with all 1s.
Expected Output:
The given array in matrix form is :
0 1 0 1 1
1 1 1 1 0
1 1 1 1 0
1 1 1 1 0
1 1 1 1 1
0 1 0 1 0
The maximum size sub-matrix is:
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1 */

#include <stdio.h>
#include <stdlib.h>

#define N 5

void print_arr(int mat[][N], int r, int c) {
	for(int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                        printf("%d ", mat[i][j]);
                }
		printf("\n");
        }
}

int min (int a, int b, int c) {
	return ((a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c));
}

void subarrayOnes(int mat[][N], int r, int c) {
	int sub[r][c];

	for(int i = 0; i < r; i++) 
              sub[i][0] = mat[i][0];
        
	for(int j = 0; j < c; j++) 
              sub[0][j] = mat[0][j];
	

	for(int i = 1; i < r; i++) {
                for (int j = 1; j < c; j++) {
			if (mat[i][j] == 1) 
				sub[i][j] = min(sub[i][j-1], sub[i-1][j], sub[i-1][j-1]) + 1;
			else
				sub[i][j] = 0;
		}
	}
	printf("subArray : \n");
	print_arr(sub, r , c);

	int max = sub[0][0];
	int x = 0, y = 0;

	for(int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
			if (max < sub[i][j]) {
				max = sub[i][j];
				x = i;
				y = j;
			}
		}
	}

	printf("max : %d, x : %d, y : %d\n", max,x,y);

	if (max > 0) {
        	printf("subArray Ones: \n");
        	for (int i = x; i > x - max; i--) {
            	      for (int j = y; j > y - max; j--) {
                	 printf("%d ", mat[i][j]);
		      }
            	      printf("\n");
		}
   	 } else {
        	printf("No subarray of ones found.\n");
	 }
}
			

int main () {

	int mat [6][5] = {{0, 1, 0, 1, 1},
                            {1, 1, 1, 1, 0},
                            {1, 1, 1, 1, 0},
                            {1, 1, 1, 1, 0},
                            {1, 1, 1, 1, 1},
                            {0, 1, 0, 1, 0}};
	/*int mat[N][N];
	int r,c;
	printf("Enter the row & column : ");
	scanf("%d%d", &r,&c);

	for(int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			mat[i][j] = rand() % 2;
		}
	}*/
	int r = 6, c = 5;
	printf("Matrix : \n");
	print_arr(mat, r, c);
	
	subarrayOnes(mat, r ,c);

	return 0;
}


