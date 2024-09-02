
/*
 * Count the number of digits in the number. Here, 153 has 3 digits.
   Raise each digit to the power of the number of digits and sum them:

   1^3 + 5^3 + 3^3 = 1+125+27=153

   Since the sum of the digits raised to the power of the number of digits equals the original number, 153 is an Armstrong number. */


#include <stdio.h>
#include <math.h>

int power(int r, int c) {
	int s = r;
	for (int i = 1; i < c; i++) {
		s = s * r;
	}

	return s;
}


int main() {
	int N,c = 0;
	printf("Enter the Number : ");
	scanf("%d", &N);

	int t = N;

	while (t) {
		t /= 10;
		c++;
	}

	t = N;
	int r,s = 0;

	while (t) {
		r = t % 10;
		s = s + pow(r,c); /* or s = s + power(r,c); */
		t = t / 10;
	}

	if (s == N) 
		printf("%d is Armstrong Number\n", N);
	else 
		printf("%d is Not an Armstrong Number\n", N);

	return 0;
}






