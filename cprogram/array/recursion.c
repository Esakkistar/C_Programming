/*
 Task

There is a series, , where the next term is the sum of pervious three terms. Given the first three terms of the series, , , and  respectively, you have to output the nth term of the series using recursion.

Recursive method for calculating nth term is given below.

Input Format

The first line contains a single integer, .

The next line contains 3 space-separated integers, , , and .

Constraints

Output Format

Print the nth term of the series, .

Sample Input 0

5
1 2 3
Sample Output 0

11     */


#include <stdio.h>

int Nth_term (int n) {
	if (n == 1)
		return 1;
	
	if (n == 2)
		return 2;

	if (n == 3)
		return 3;

	return Nth_term(n-1) + Nth_term(n-2) + Nth_term(n-3);
}


int main () {
	int n;
	printf("Enter the Number : ");
	scanf("%d", &n);

	int ret = Nth_term(n);

	printf("Series of %d th term : %d \n", n, ret);

	return 0;
}
