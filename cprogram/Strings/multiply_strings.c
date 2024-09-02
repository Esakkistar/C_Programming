#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

char* multiply_strings(char* s1, char* s2) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int maxlen = len1+len2;
	int n1, n2, mul;
	
	char* prod = (char*) malloc((maxlen+1) * sizeof(char));
	for (int i = 0; i < maxlen; i++) {
		prod[i] = '0';
	}

	for (int i = len1-1; i >= 0; i--) {
		for(int j = len2-1; j >= 0; j--) {
			mul = (s1[i] - '0') * (s2[j] - '0') + (prod[i+j+1] - '0');
			prod[i+j+1] = (mul % 10) + '0';
			prod[i+j] += (mul / 10);
		}
	}

	int i = 0;
	while (i < maxlen && prod[i] == '0') {
		i++;
	}
	if (i == maxlen) {
		strcpy(prod, "0");
		return prod;
	}

	prod = (char*)realloc(prod, (maxlen-i+1)*sizeof(char));
	strcpy(prod, prod+i);
	return prod;
}

int main () {
	char s1[MAX];
	char s2[MAX];

	printf("Enter str1 : ");
    	scanf("%s", s1);
    	printf("Enter str2 : ");
    	scanf("%s", s2);

	char* mul = multiply_strings(s1,s2);

	printf("Product of two strings : %s * %s : %s\n", s1, s2, mul);

	free(mul);

	return 0;
}



