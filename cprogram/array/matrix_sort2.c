#include <stdio.h>
#include <stdlib.h>

void swap (int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printMatrix(int** mat, int r, int c) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                    printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
}

void sortMatrix(int* s, int low, int high) {
    if (low < high) {
    	int pivot = s[low];
    	int start = low;
    	int end = high;
    
    	while (start < end) {
            while (s[start] <= pivot) {
            	 start++;
	    }
            while (s[end] > pivot) {
                 end--;
	    }
            if (start < end) {
                 swap(&s[start], &s[end]);
	    }
	}
    	swap(&s[low], &s[end]);
    
	sortMatrix(s, low, end-1);
    	sortMatrix(s, end+1, high);
    }
}

void freematrix (int** mat , int r) {
        for (int i = 0; i < r; i++) {
                free(mat[i]);
        }
        free(mat);
}

int main() {
   int r,c,newRow;
        printf("Enter the row & column : ");
        scanf("%d%d", &r,&c);

        int** mat = (int**) malloc(r * sizeof(int*));
        
        for (int i = 0; i < r; i++) {
            mat[i] = (int*) malloc(c * sizeof(int));
            for (int j = 0; j < c; j++) {
                    mat[i][j] = rand() % 50 + 1;
            }
        }
        printf("Matrix : \n");
        printMatrix(mat, r, c);
        
        int n = r*c;
        int k = 0;
        int* sub = (int*) malloc(n * sizeof(int));
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                    sub[k++] = mat[i][j];
            }
        }
        
        sortMatrix(sub, 0, n-1);
        
        for (int i = 0; i < n; i++) {
            printf("%d ", sub[i]);
        }
        printf("\n");
        
        k = 0;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                    mat[i][j] = sub[k++];
            }
        }
        
        printf("Sorted Matrix : \n");
        printMatrix(mat, r, c);

	free(sub);
	freematrix (mat, r);
        
        return 0;
}
