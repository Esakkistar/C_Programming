/*
 * Count Distinct Subsequences
Last Updated : 10 Jul, 2024
Given a string, find the count of distinct subsequences of it.

Examples:

Input: str = “gfg”
Output: 7
Explanation: The seven distinct subsequences are “”, “g”, “f”, “gf”, “fg”, “gg” and “gfg”

Input: str = “ggg”
Output: 4
Explanation: The four distinct subsequences are “”, “g”, “gg” and “ggg” */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_seq(char* s) {
	for (int i = 0; s[i] != '\0'; i++) {
		printf("%c",s[i]);
	}
	printf("\n");
}

void subseq(char* s, int len, int index, char* sub, int subsize) {
	if (index == len) {
		sub[subsize] = '\0';
		printf("subsize : %d\n", subsize);
		print_seq(sub);
		return;
	}
	sub[subsize] = s[index];
	subseq(s, len, index+1, sub, subsize+1);
	subseq(s, len, index+1, sub, subsize);
}
int main () {
	char* s = "ggg";
	int n = strlen(s);

	char* sub = (char*) malloc ((n+1)* sizeof(char));
	subseq(s, n, 0, sub, 0);

	free(sub);

	return 0;
}



