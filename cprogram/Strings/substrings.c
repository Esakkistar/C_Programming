/*
 * Given a string that consists of only 0s, 1s and 2s, count the number of substrings that have an equal number of 0s, 1s, and 2s.

Examples:

Input: str = “0102010”
Output:  2
Explanation: Substring str[2, 4] = “102” and substring str[4, 6] = “201” has equal number of 0, 1 and 2

Input: str = “102100211”
Output: 5 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_seq(char* s) {
    printf("%s\n", s);
}

int is_duplicate(char** unique_subs, int count, char* sub) {
    for (int i = 0; i < count; i++) {
        if (strcmp(unique_subs[i], sub) == 0) {
            return 1; // Found duplicate
        }
    }
    return 0; // Not a duplicate
}

void subseq(char* s, int len, int index, char* sub, int subsize, char** unique_subs, int* unique_count) {
    if (index == len) {
        sub[subsize] = '\0'; // Null-terminate the string
        if (subsize > 0 && !is_duplicate(unique_subs, *unique_count, sub)) {
            unique_subs[*unique_count] = strdup(sub); // Store unique subsequence
            (*unique_count)++;
        }
        return; // Exit function after processing
    }
    sub[subsize] = s[index];
    subseq(s, len, index + 1, sub, subsize + 1, unique_subs, unique_count);
    subseq(s, len, index + 1, sub, subsize, unique_subs, unique_count);
}

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void process_unique_subs(char** unique_subs, int unique_count) {
    
   // qsort(unique_subs, unique_count, sizeof(char*), compare);
 
    int zeros = 0, ones = 0,  twos = 0;
    int cnt = 0; 
    for (int i = 0; i < unique_count; i++) {
	    if ( (strlen(unique_subs[i])) >= 3) {
		    //printf("%s\n", unique_subs[i]);
		    for (int j = 0; unique_subs[i][j] != 0; j++) {
			    if (unique_subs[i][j] == '0') 
				    zeros++;
			    else if (unique_subs[i][j] == '1')
				    ones++;
			    else
				    twos++;
		    }
	    }
	    else continue;


	    if (zeros == ones && ones == twos) {
		cnt++;
		printf("%s\n", unique_subs[i]);
	    }
	    zeros = ones = twos = 0;
            free(unique_subs[i]); 
    }
    printf("cnt : %d\n", cnt);
}


int main () {
    char* s = "0102010";
    int n = strlen(s);
    
    int max_subs = 1000; // Initial size, can be adjusted as needed
    char** unique_subs = (char**) malloc(max_subs * sizeof(char*));
    int unique_count = 0;

    char* sub = (char*) malloc ((n + 1) * sizeof(char));
    
    subseq(s, n, 0, sub, 0, unique_subs, &unique_count);
    
    process_unique_subs(unique_subs, unique_count);
    
    free(sub);
    free(unique_subs);
    
    return 0;
}


/*
 * // Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int findsub(char* t) {
    int c[256];
    memset(c, 0, sizeof(c));

    int n = strlen(t);

    for (int i = 0; t[i] != 0; i++) {
        c[(unsigned char)t[i]]++;
    }

    for (int i = 0; i < n-1; i++) {
        if ( c[t[i]] != c[t[i+1]]) {
            return 0;
        }
    }
    return 1;
}
int main() {

       char* s = "102100211";
       int n =strlen(s);
       for (int i = 0; i < n; i++) {
           for (int j = i+2; j < n; j++) {
               char t[10] = "";
               strncpy(t, s+i, j-i+1);
               if (findsub(t)) {
                    printf("%s\n", t);
               }
           }
       }
    return 0;
} */
