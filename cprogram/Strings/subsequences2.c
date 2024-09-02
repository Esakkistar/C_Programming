#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print a string
void print_seq(char* s) {
    printf("%s\n", s);
}

// Function to check if a subsequence is already in the array
int is_duplicate(char** unique_subs, int count, char* sub) {
    for (int i = 0; i < count; i++) {
        if (strcmp(unique_subs[i], sub) == 0) {
            return 1; // Found duplicate
        }
    }
    return 0; // Not a duplicate
}

// Recursive function to generate all subsequences
void subseq(char* s, int len, int index, char* sub, int subsize, char** unique_subs, int* unique_count) {
    if (index == len) {
        sub[subsize] = '\0'; // Null-terminate the string
        if (subsize > 0 && !is_duplicate(unique_subs, *unique_count, sub)) {
            unique_subs[*unique_count] = strdup(sub); // Store unique subsequence
            (*unique_count)++;
        }
        return; // Exit function after processing
    }
    // Include the current character
    sub[subsize] = s[index];
    subseq(s, len, index + 1, sub, subsize + 1, unique_subs, unique_count);
    // Exclude the current character
    subseq(s, len, index + 1, sub, subsize, unique_subs, unique_count);
}

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Function to remove duplicates and sort unique subsequences
void process_unique_subs(char** unique_subs, int unique_count) {
    // Sort the unique subsequences
    
    for (int i = 0; i < unique_count; i++) {
	    printf("%s\n", unique_subs[i]);
    }
    printf("-----------------\n");

    qsort(unique_subs, unique_count, sizeof(char*), compare);
    
    // Print sorted unique subsequences
    for (int i = 0; i < unique_count; i++) {
        printf("%s\n", unique_subs[i]);
        free(unique_subs[i]); // Free allocated memory for each subsequence
    }
}

int main () {
    char* s = "gfg";
    int n = strlen(s);
    
    // Allocate memory for storing unique subsequences
    int max_subs = 100; // Initial size, can be adjusted as needed
    char** unique_subs = (char**) malloc(max_subs * sizeof(char*));
    int unique_count = 0;

    // Allocate memory for subsequence generation
    char* sub = (char*) malloc ((n + 1) * sizeof(char));
    
    subseq(s, n, 0, sub, 0, unique_subs, &unique_count);
    
    // Process and print unique subsequences
    process_unique_subs(unique_subs, unique_count);
    
    // Free allocated memory
    free(sub);
    free(unique_subs);
    
    return 0;
}

