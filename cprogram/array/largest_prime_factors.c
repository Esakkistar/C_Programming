/*
 * Write a C program to find the largest prime factor of the number 438927456 */

#include <stdio.h>
#include <math.h>

int Isprime(int n) {
    if (n % 2 == 0) return 0;

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
  
  unsigned long int n = 438927456;
  int max = 0;

  for (int i = 1; i <= sqrt(n); i++) {
      if (n % i == 0 ) { 
	      if ( Isprime(i) && i > max) {
           	 printf("%d ", i);
            	 max = i;
	      }
              int f = n/i;
              if (f != i && Isprime(f) && f > max) {
                 printf("%d ", f);
                 max = f;
	      }
      }
  }

  printf("\nmax : %d\n", max);
  return 0;
}

