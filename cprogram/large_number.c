#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

int customcompare(char* a, char* b) {
	char ab[MAX], ba[MAX];
	
	sprintf(ab, "%s%s", a, b);
	sprintf(ba, "%s%s", b, a);

	//return strcmp(ab, ba) > 0;
	return strcmp(ba, ab);
}

void createlargeNumber(char** s, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (customcompare(s[i], s[j]) > 0) {
				char* t = s[i];
				s[i] = s[j];
				s[j] = t;
			}
		}
	}
	for (int i = 0; i < N; i++) {
                printf("%s", s[i]);
        }
	printf("\n");

}

int compare (const void *a, const void *b) {
	char ab[MAX], ba[MAX];
	
	sprintf(ab, "%s%s", *(const char **)a, *(const char **)b);
	sprintf(ba, "%s%s", *(const char **)b, *(const char **)a);

	return strcmp(ba, ab);
}

int main () {
	int N;
	printf("Enter the No.of Strings : ");
	scanf("%d", &N);

	char** str = (char**)malloc(N * sizeof(char*));

	for (int i = 0; i < N; i++) {
		str[i] = (char*)malloc(MAX*sizeof(char));
		scanf("%s", str[i]);
		//scanf("%[^\n]%*c", str[i]);
		str[i] = realloc(str[i], strlen(str[i])+1);
	}
        printf("Before Sort : \n");
	for (int i = 0; i < N; i++) {
		printf("%s\n", str[i]);
	}

	createlargeNumber(str, N);

	printf("After Sort : \n");
        for (int i = 0; i < N; i++) {
                printf("%s\n", str[i]);
        }

/*	qsort(str, N, sizeof(char*), compare);

	for (int i = 0; i < N; i++) {
                printf("%s", str[i]);
	}
	printf("\n"); */

	return 0;
}

