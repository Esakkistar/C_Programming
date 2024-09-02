/*
 * Count Number of Islands: Given a binary matrix representing a grid, where 1 represents land and 0 represents water, count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. */

#include <stdio.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

// Function to perform DFS
void DFS(int matrix[ROWS][COLS], bool visited[ROWS][COLS], int row, int col) {
    // Check boundaries and if cell is water or already visited
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || matrix[row][col] == 0 || visited[row][col])
        return;

    // Mark this cell as visited
    visited[row][col] = true;

    // Explore all 4 directions (up, down, left, right)
    DFS(matrix, visited, row - 1, col); // up
    DFS(matrix, visited, row + 1, col); // down
    DFS(matrix, visited, row, col - 1); // left
    DFS(matrix, visited, row, col + 1); // right
}

// Function to count the number of islands
int countIslands(int matrix[ROWS][COLS]) {
    bool visited[ROWS][COLS];
    int count = 0;

    // Initialize visited matrix
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            visited[i][j] = false;

    // Traverse the matrix
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // If we find a land cell that is not visited
            if (matrix[i][j] == 1 && !visited[i][j]) {
                // Perform DFS to mark all connected land cells
                DFS(matrix, visited, i, j);
                // Increment island count
                count++;
            }
        }
    }

    return count;
}

int main() {
    int matrix[ROWS][COLS] = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };

    int numberOfIslands = countIslands(matrix);
    printf("Number of islands: %d\n", numberOfIslands);

    return 0;
}

