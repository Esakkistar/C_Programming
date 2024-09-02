/*
 * Distinct characters in a string are the unique characters that appear in the string, regardless of how many times they occur. For example:

   In the string "apple", the distinct characters are a, p, l, and e. So, the count of distinct characters is 4.
   In the string "banana", the distinct characters are b, a, and n. So, the count of distinct characters is 3. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_S 50
#define MAX 100

void lexicographically_sort (char** str, int n) {
	char temp[MAX];
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if ( (strcmp (str[i],str[j])) > 0 ) {
				strcpy(temp, str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],temp);
			}
		}
	}
}

void lexicographically_sort_reverse(char** str, int n) {
	char temp[MAX];
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if ( (strcmp (str[i],str[j])) < 0 ) {
				strcpy(temp, str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],temp);
			}
		}
	}
}

void sort_by_length(char** str, int n) {
	char temp[MAX];
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if ( (strlen(str[i]) > strlen(str[j])) ) {
				strcpy(temp, str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],temp);
			}
			else if ( (strlen(str[i]) == strlen(str[j])) && ((strcmp (str[i],str[j])) > 0 ) ) {
				strcpy(temp, str[i]);
                                strcpy(str[i],str[j]);
                                strcpy(str[j],temp);
			}
		}
	}
}
int count (char* str) {
	int ch[256] = {0};
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		char s = tolower(str[i]);
		if ( ch[(unsigned char)s] == 0) {
			ch[(unsigned char)s] = 1;
			++count;
		}
	}
	return count;
}

int compare_fun(char *a, char* b) {
	int ca = count(a);
	int cb = count(b);

	if (ca == cb) 
		return strcmp(a,b);
        
	return ca - cb;
}

void sort_by_number_of_distinct_characters (char** str, int n) {
	char temp[MAX];
        for (int i = 0; i < n-1; i++) {
                for (int j = i+1; j < n; j++) {
                        if ( (compare_fun (str[i],str[j])) > 0 ) {
                                strcpy(temp, str[i]);
                                strcpy(str[i],str[j]);
                                strcpy(str[j],temp);
                        }
                }
        }
}

int main () {
	char** str;

	int N;

	printf("Enter the No.of strings : ");
	scanf("%d", &N);

	str = (char**) malloc(N * sizeof(char*));

	for (int i = 0; i < N; i++) {
		str[i] = (char*)malloc(MAX*sizeof(char));
		scanf(" %[^\n]%*c", str[i]);

		str[i] = realloc(str[i], strlen(str[i]+1));
	}

	printf("Before Sort : \n");
	for (int i = 0; i < N; i++) {
		printf("%d. %s\n", i+1, str[i]);
	}

        /* Copy original array of strings
        char **copy = (char **)malloc(N * sizeof(char *));
        for (int i = 0; i < N; i++) {
        	copy[i] = (char *)malloc((strlen(str[i]) + 1) * sizeof(char));
        	strcpy(copy[i], str[i]);
	}*/ 	 

	lexicographically_sort(str,N);
	
	printf("lexicographilly Sort : \n");
	for (int i = 0; i < N; i++) {
		printf("%d. %s\n", i+1, str[i]);
	}
	
	lexicographically_sort_reverse(str,N);
	
	printf("lexicographilly Sort Reverse : \n");
	for (int i = 0; i < N; i++) {
		printf("%d. %s\n", i+1, str[i]);
	}

	sort_by_length(str,N);
	
	printf("Sort by Length : \n");
	for (int i = 0; i < N; i++) {
		printf("%d. %s\n", i+1, str[i]);
	}

	sort_by_number_of_distinct_characters(str,N);
	printf("Sort_by_number_of_distinct_characters : \n");
	for (int i = 0; i < N; i++) {
		printf("%d. %s\n", i+1, str[i]);
	}
	
	for (int i = 0; i < N; i++) {
 	      free(str[i]);
	}

	free(str);

	return 0;
}


