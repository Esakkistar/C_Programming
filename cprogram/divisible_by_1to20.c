/*
 * Write a C program to find the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 */

#include <stdio.h>

int gcd(long a, long b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int lcm (long a, long b) {
    return (a*b) / gcd(a, b);
}
int main() {
    long res = 1;
   for (int i = 1; i <= 20; i++) {
       res = lcm(res, i);
   }
   printf("%ld \n", res);

   return 0;
}
