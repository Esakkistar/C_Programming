#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

int main() {
    char **arr;
    int n;

    // Input the number of strings
    printf("Enter number of strings: ");
    scanf("%d", &n);
    getchar(); // Consume newline character

    // Allocate memory for the array of strings
    arr = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(MAX_LENGTH * sizeof(char));
    }

    // Input the strings
    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        fgets(arr[i], MAX_LENGTH, stdin);
        arr[i][strcspn(arr[i], "\n")] = 0; // Remove newline character
    }

    // Find duplicates
    int *duplicates = (int *)calloc(n, sizeof(int)); // Array to mark duplicates
    int found_duplicates = 0;
    int count[MAX_LENGTH] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) == 0) {
                duplicates[j] = 1;
		count[i]++;
                found_duplicates = 1;
            }
        }
	if (!found_duplicates) {
	        duplicates[i] = 1;
	}
	found_duplicates = 0;
    }

    // Print duplicates
    printf("\nDuplicate strings:\n");
    int found = 1;
    for (int i = 0; i < n; i++) {
        if (!duplicates[i]) {
            printf("%s - %d\n", arr[i],count[i]+1);
	    found = 0;
        }
    }

    if (found) {
        printf("No duplicate strings found.\n");
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    free(duplicates);

    return 0;
}

