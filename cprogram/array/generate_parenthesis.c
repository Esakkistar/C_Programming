#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_parenthesis(int n, int open, int close, char* pair, int index) {
	if (close == n) {
		pair[index] = '\0';
		printf("%s\n", pair);
		return;
	}

	if (open < n) {
		pair[index] = '(';
		generate_parenthesis(n, open+1, close, pair, index+1);
	}
	
	if (close < open) {
		pair[index] = ')';
		generate_parenthesis(n, open, close+1, pair, index+1);
	}

}


int main () {
	int n;
	
	printf("Enter the Number : ");
	scanf("%d", &n);

	char* pair = (char*) malloc((2*n+1) * sizeof(char));
	pair[2*n] = '\0';

	generate_parenthesis(n, 0, 0, pair, 0);

	free(pair);

	return 0;
}



