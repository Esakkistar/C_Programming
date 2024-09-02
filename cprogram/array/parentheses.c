#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(char* current, int open, int close, int n, char** result, int* resultSize) {
    if (strlen(current) == 2 * n) {
        result[*resultSize] = strdup(current); // Add current string to result
        (*resultSize)++;
        return;
    }

    if (open < n) {
        // Add an open parenthesis
        current[strlen(current)] = '(';
        current[strlen(current) + 1] = '\0';
        backtrack(current, open + 1, close, n, result, resultSize);
        current[strlen(current) - 1] = '\0'; // Remove the last character
    }

    if (close < open) {
        // Add a close parenthesis
        current[strlen(current)] = ')';
        current[strlen(current) + 1] = '\0';
        backtrack(current, open, close + 1, n, result, resultSize);
        current[strlen(current) - 1] = '\0'; // Remove the last character
    }
}

char** generateParentheses(int n, int* returnSize) {
    // Allocate memory for the result
    int maxSize = 1;
    for (int i = 0; i < n; i++) {
        maxSize *= 2 * (i + 1);
    }
    char** result = (char**)malloc(maxSize * sizeof(char*));
    *returnSize = 0;

    // Initialize a buffer for current string
    char* current = (char*)malloc((2 * n + 1) * sizeof(char));
    current[0] = '\0'; // Start with an empty string
    printf ("Strlen : %ld\n", strlen(current));
    // Start backtracking
    backtrack(current, 0, 0, n, result, returnSize);
    
    printf("MAxsize : %d, ReturnSize : %d\n",maxSize,*returnSize);

    // Free the allocated memory for the current string
    free(current);

    return result;
}

int main() {
    int n;
    int returnSize = 0;
    printf("Enter the Number : ");
    scanf("%d", &n);
    char** combinations = generateParentheses(n, &returnSize);

    // Print the results
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", combinations[i]);
        free(combinations[i]); // Free each combination string
    }

    // Free the result array
    free(combinations);

    return 0;
}

