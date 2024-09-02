/*
 * Write a program in C to return only the unique rows from a given binary matrix.

Expected Output:
The given array is :
0 1 0 0 1
1 0 1 1 0
0 1 0 0 1
1 0 1 0 0
The unique rows of the given array are :
0 1 0 0 1
1 0 1 1 0
1 0 1 0 0 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define R 4
#define C 5

int Isunique(int* c, int index, int r) {
    for (int i = 0; i < index; i++) {
        if (c[i] == r) {
            return 0;
        }
    }
    return 1;
}

int main() {
      int arr[R][C] = {
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0}
    };
    int cnt = 0;
    int count[R], index = 0;
    memset(count, 0, sizeof(count));
    for (int i = 0; i < R; i++) {
        for (int j = i+1; j < R; j++) {
            for (int k = 0; k < C; k++) {
                if (arr[i][k] == arr[j][k]) {
                    cnt++;
                }
            }
            if (cnt == C) {
                count[index++] = j;
            }
            cnt = 0;
        }
    }
    int uniqueRow[R][C], r = 0;
    printf("cnt : %d\n", index);
    for (int i = 0; i < R; i++) {
        if (Isunique(count,index, i)) {
            for (int j = 0; j < C; j++) {
                uniqueRow[r][j] = arr[i][j];
            }
            r++;
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d ",  uniqueRow[i][j]);
        }
        printf("\n");
    }
    return 0;
}
