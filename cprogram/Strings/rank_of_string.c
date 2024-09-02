/*
 * Lexicographic rank of a String
Last Updated : 16 Oct, 2023
Given a string str, find its rank among all its permutations when sorted lexicographically.

Note: The characters a string are all unique.

Examples:

Input: str = “acb”
Output: 2
Explanation: If all the permutations of the string are arranged lexicographically they will be “abc”, “acb”, “bac”, “bca”, “cab”, “cba”. From here it can be clearly that the rank of str is 2.

Input: str = “string”
Output: 598

Input: str[] = “cba”
Output: Rank = 6 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fact (int n) {
    if (n <= 1) {
        return 1;
    }
    return n*fact(n-1);
}
void swap_char(char* a, char* b) {
    char ch = *a;
    *a = *b;
    *b = ch;
}

void permutation(char* s, int start, int end, char** per, int* index) {
    if (start == end ) {
        s[end+1] = '\0';
        strcpy(per[*index], s);
        (*index)++;
    }
    for (int i = start; i <= end; i++) {
        swap_char(&s[start], &s[i]);
        permutation(s, start+1, end, per, index);
        swap_char(&s[start], &s[i]);
    }
}
void sort(char** p, int n) {
    char t[20];
    for(int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (strcmp(p[i], p[j]) > 0) {
                strcpy(t,p[i]);
                strcpy(p[i], p[j]);
                strcpy(p[j], t);
            }
        }
    }
}

void sort_string(char* s) {
	int n = strlen(s);
	for(int i = 0; i < n; i++) { 
		for (int j = i+1; j < n; j++) {
			if (s[i] > s[j]) {
				swap_char(&s[i], &s[j]);
			}
		}
	}
}

int main() {
    char* s = "string";
    int len = strlen(s);
    char temp[20];
    strcpy(temp, s);
    sort_string(temp);
    int max = fact(len);
    int index = 0;
    char** per = (char**) malloc (max * sizeof(char*));

    for (int i = 0; i < max; i++) {
        per[i] = (char*) malloc((len+1) * sizeof(char));
    }
    permutation(temp, 0, strlen(temp) - 1, per, &index);

    sort(per, max);

    for (int i = 0; i < max; i++) {
	    printf("%s\n", per[i]);
        if (strcmp(s, per[i]) == 0) {
            printf("%d - %s\n", i+1, per[i]);
        }
    }
    return 0;
}
