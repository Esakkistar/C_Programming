#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

void bubbleSort(char arr[][MAX_LENGTH], int n) {
    char temp[MAX_LENGTH];
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) {
                // Swap the strings if they are in the wrong order
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
    }
}

int main() {
    char arr[MAX_STRINGS][MAX_LENGTH];
    int n;

    // Input the number of strings
    printf("Enter number of strings: ");
    scanf("%d", &n);
    getchar();  // Consume newline character

    // Input the strings
    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        fgets(arr[i], MAX_LENGTH, stdin);
        arr[i][strcspn(arr[i], "\n")] = 0;  // Remove newline character
    }

    // Sort the strings using bubble sort
    bubbleSort(arr, n);

    // Output the sorted strings
    printf("\nSorted strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}

