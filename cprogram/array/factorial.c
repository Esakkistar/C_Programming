#include <stdio.h>


int fact (int N) {
	int fact = 1;
	while (N) {
		fact = fact * N--;
	}
	return fact;
}

int fact_recursion(int N) {
	if (N== 0 || N == 1)
		return 1;
	return N * fact_recursion(N-1);
}

		
int main () {
	int N;

	printf ("Enter the Number : ");
	scanf("%d", &N);

	printf ("Factorial : %d\n", fact(N));
	printf ("Factorial using recursion : %d\n", fact_recursion(N));

	return 0;
}
