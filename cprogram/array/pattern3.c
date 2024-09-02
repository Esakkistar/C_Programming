#include <stdio.h>

void printPattern(int n) {
    // Loop through each row
    for (int i = 0; i < n; i++) {
        // Loop through each column
        for (int j = 0; j < n; j++) {
            // Calculate the value to be printed based on the minimum distance from any edge
            int min = i < j ? i : j;
            min = min < n - i - 1 ? min : n - i - 1;
            min = min < n - j - 1 ? min : n - j - 1;
            printf("%d ", n - min);
        }
        printf("\n");
    }
}

int main() {
    int n;

    // Read the size of the pattern from the user
    printf("Enter the size of the pattern: ");
    scanf("%d", &n);

    // Ensure the size is odd
    if (n % 2 == 0) {
        printf("Please enter an odd number.\n");
        return 1;
    }

    // Print the pattern
    printPattern(n);

    return 0;
}

