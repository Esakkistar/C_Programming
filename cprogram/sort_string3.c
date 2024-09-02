#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_S 50
#define MAX 100

int lexicographically_sort (char* a, char* b) {
	return strcmp(a,b);
}

int lexicographically_sort_reverse(char* a, char* b) {
        return strcmp(b,a);
}

int sort_by_length (char* a, char* b) {
	if (strlen(a) == strlen(b))
		return strcmp(a,b);

	return strlen(a) > strlen(b);
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

int sort_by_number_of_distinct_characters (char *a, char* b) {
	int ca = count(a);
	int cb = count(b);

	if (ca == cb) 
		return strcmp(a,b);
        
	return ca - cb;
}
void string_sort (char** str, int n, int (*cmp_func)(char* a, char* b)) {
	char* temp;
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if ( (cmp_func(str[i],str[j])) > 0 ) {
                                temp = str[i];
				str[i] = str[j];
				str[j] = temp;
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
	//	scanf("%s", str[i]);

		str[i] = realloc(str[i], strlen(str[i])+1);
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
	
	string_sort(str,N,lexicographically_sort);

	printf("lexicographilly Sort : \n");
	for (int i = 0; i < N; i++) {
		printf("%d. %s\n", i+1, str[i]);
	}


	string_sort(str,N,lexicographically_sort_reverse);

	printf("lexicographilly Sort Reverse: \n");
	for (int i = 0; i < N; i++) {
		printf("%d. %s\n", i+1, str[i]);
	}

	string_sort(str,N,sort_by_length);

	printf("Sort_by_length : \n");
	for (int i = 0; i < N; i++) {
		printf("%d. %s\n", i+1, str[i]);
	}

	string_sort(str,N,sort_by_number_of_distinct_characters);

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

