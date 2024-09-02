/*
 * Write a C program to find the largest palindrome made from the product of two 3-digit numbers. */

#include <stdio.h>

int palindrome(int n) {
    int sum = 0;
    int t = n;
    while (t > 0) {
        sum = sum * 10 + (t % 10);
        t = t / 10;
    }
    return n == sum;
}
int main() {
    int p, max = 0;
   for (int i = 100; i <= 999; i++) {
       for (int j = i; j <= 999; j++) {
           p = i*j;
           if (palindrome(p) && p > max) {
               max = p;
           }
       }
   }
   printf("Largest 3 digits palindrome number : %d\n", max);

    return 0;
}
