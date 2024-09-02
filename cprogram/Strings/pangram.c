/*
 * Check if given String is Pangram or not
Last Updated : 21 Mar, 2023
Given a string Str. The task is to check if it is Pangram or not.

A pangram is a sentence containing every letter in the English Alphabet.

Examples:

Input: “The quick brown fox jumps over the lazy dog”
Output: is a Pangram
Explanation: Contains all the characters from ‘a’ to ‘z’]

Input: “The quick brown fox jumps over the dog”
Output: is not a Pangram
Explanation: Doesn’t contain all the characters from ‘a’ to ‘z’, as ‘l’, ‘z’, ‘y’ are missing */

#include <stdio.h>
#include <string.h>
#include <ctype.h>


int pangram(char* s) {
	int freq[256];
	memset (freq, 0, sizeof(freq));

	int flag = 1;
	for (int i = 0; s[i] != '\0'; i++) {
		int ch = tolower(s[i]);
		freq[(unsigned char)ch] = 1;
	}

	for (int i = 0; s[i] != '\0'; i++) {
		if ( ('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z' ))
            		printf("%c ", s[i]);
	}

	/*for (int i = 97; i <= 122; i++) {
		if (!freq[i]) {
			printf("%c ", i);
			flag = 0;
		}
	}*/
	printf("\n");

	if (flag)
	     return 1;
	else
	    return 0;
}

int main () {
	char* s = "The quick brown fox jumps over the dog";

	if (pangram(s))
		printf("String is Pangram\n");
	else
		printf("String is not Pangram\n");

	return 0;

}
