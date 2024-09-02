#include <stdio.h>
#include <stdlib.h>

int N; // Variable to store the size of the board

void print_board(int** b) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int** b, int row, int col) {
    for (int i = 0; i < col; i++) {
        if (b[row][i])
            return 0;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (b[i][j])
            return 0;
    }

    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (b[i][j])
            return 0;
    }

    return 1;
}

int solveN_queens(int** b, int col) {
    if (col >= N)
        return 1;

    for (int i = 0; i < N; i++) {
        if (isSafe(b, i, col)) {
            b[i][col] = 1;

            if (solveN_queens(b, col + 1))
                return 1;

            b[i][col] = 0;
        }
    }

    return 0; // Ensure a return value is provided
}

int main() {
    printf("Enter the No. of Queens: ");
    scanf("%d", &N);

    int** board = (int**) malloc(N * sizeof(int*));

    for (int i = 0; i < N; i++) {
        board[i] = (int*) malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (solveN_queens(board, 0))
        print_board(board);
    else
        printf("Can't arrange Queens\n");

    for (int i = 0; i < N; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}

