/*
 * Encrypt the string – 2
Last Updated : 26 Apr, 2023
Given a string S consisting of N, lower case English alphabet, it is also given that a string is encrypted by first replacing every substring of the string consisting of the same character with the concatenation of that character and the hexadecimal representation of the size of the substring and then revering the whole string, the task is to find the encrypted string.

Note: All Hexadecimal letters should be converted to Lowercase letters.

Examples:

Input: S = “aaaaaaaaaaa”
Output: ba
Explanation:

First convert the given string to “a11” i.e. write, character along with its frequency.
Then, change “a11” to “ab” because 11 is b in hexadecimal.
Then, finally reverse the string i.e “ba”.
Input: S = “abc”
Output: 1c1b1a */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* encrpt_string (char* s) {
	char h[] = "0123456789ABCDEF";
	char* encrpt = (char*) malloc (100 * sizeof(char));
	int cnt;
	int len = strlen(s);
	int k = 0;

	printf("len : %d\n", len);

	//int* f = (int*) calloc (len, sizeof(int));
	int f[len];
	for (int i = 0; i < len; i++) {
		f[i] = 1;
	}

	for (int i = 0; i < len; i++) {
		cnt = 1;
		char ch1 = tolower(s[i]);
		for (int j = i+1; j < len; j++) {
			char ch2 = tolower(s[j]);
			if (ch1 == ch2) {
				cnt++;
				f[j] = 0;
			}
		}
		if (f[i]) {
			printf("%c ", s[i]);
			encrpt[k++] = s[i];
		        encrpt[k++] = h[cnt];
		}
	}

	encrpt = (char*) realloc (encrpt, k+1);
	encrpt[k] = '\0';

	//free (f);
	return encrpt;
}

int main () {
	char s[20];
	printf("Enter the string : ");
	scanf(" %[^\n]%*c", s);

	char* encrpt = encrpt_string(s);

	printf("Encrpted String : ");
	for (int i = strlen(encrpt) - 1; i >= 0; i--) {
		printf("%c", encrpt[i]);
	}
	printf("\n");

	free(encrpt);

	return 0;
}

        



	
