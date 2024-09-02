/*
 *
Check divisibility by 7
Given a number N, the task is to check if it is divisible by 7 or not.
Note: You are not allowed to use the modulo operator, floating point arithmetic is also not allowed.

Naive approach: A simple method is repeated subtraction. Following is another interesting method.
Divisibility by 7 can be checked by a recursive method. A number of the form 10a + b is divisible by 7 if and only if a – 2b is divisible by 7. In other words, subtract twice the last digit from the number formed by the remaining digits. Continue to do this until a small number.

Example: the number 371: 37 – (2×1) = 37 – 2 = 35; 3 – (2 × 5) = 3 – 10 = -7; thus, since -7 is divisible by 7, 371 is divisible by 7. */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int divide (int N, int k) {
    if (N == 0)
        return 1;
    if (N < 0)
        return 0;
    return divide(N-k, k);
}

int main () {
    int N,k;
    printf("Enter the Number: ");
    scanf("%d", &N);
    printf("Enter the Divisor : ");
    scanf("%d", &k);

    if (divide(N, k) ) {
        printf("%d is divisible by %d\n",N, k);
    }
    else {
	printf("%d is not divisible by %d\n",N, k);
    }

    return 0;
} 
/*
int isDivisibleBy7( int num ) {
    // If number is negative, make it positive
    if( num < 0 )
        return isDivisibleBy7( -num );

    // Base cases
    if( num == 0 || num == 4 )
        return 1;
    if( num < 10 )
        return 0;

    // Recur for ( num / 10 - 2 * num % 10 )
    return isDivisibleBy7( num / 10 - 2 * ( num - num / 10 * 10 ) );
}

// Driver program to test above function
int main()
{
    int num = 616;
    if( isDivisibleBy7(num ) )
        printf( "Divisible" );
    else
        printf( "Not Divisible" );
    return 0;
}
*/
