#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void sort_row_matrix(int* mat, int low, int high) {
    if (low < high) {
        int pivot = mat[low];
        int start = low;
        int end = high;
        
        while (start < end) {
            while (mat[start] <= pivot) start++;
            while (mat[end] > pivot) end--;
            if (start < end) swap(&mat[start], &mat[end]);
        }
        swap(&mat[low], &mat[end]);
        sort_row_matrix(mat, low, end-1);
        sort_row_matrix(mat, end+1, high);
    }
}
void print_matrix(int** mat, int r, int c) {
    for (int i = 0; i < r; i++) {
         for (int j = 0; j < c; j++) {
             printf("%d ", mat[i][j]);
         }
         printf("\n");
    }
}
int main() {
    int r, c;
    printf("Enter row and col : ");
    scanf("%d%d", &r, &c);
    
    int** mat = (int**) malloc(r * sizeof(int*));
    
    for (int i = 0; i < r; i++) {
        mat[i] = (int*) malloc (c * sizeof(int));
        for (int j = 0; j < c; j++) {
            mat[i][j] = rand() % 100;
        }
    }
    
    print_matrix(mat, r, c);
    
     for (int i = 0; i < r; i++) {
         sort_row_matrix(mat[i], 0, c-1);
     }
     printf("Row sorted Matrix : \n");
     print_matrix(mat, r, c);
    
    return 0;
}

