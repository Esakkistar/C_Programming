/*
 * Program for nth Catalan Number
Last Updated : 22 Nov, 2023
Catalan numbers are defined as a mathematical sequence that consists of positive integers, which can be used to find the number of possibilities of various combinations.

The nth term in the sequence denoted Cn, is found in the following formula: \frac{(2n)!}{((n + 1)! n!)}

The first few Catalan numbers for n = 0, 1, 2, 3, … are : 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …   */

#include <stdio.h>
#include <string.h>

unsigned long int catalan (int n) {
    if (n <= 1) {
        return 1;
    }

    unsigned long int res = 0;
    for (int i = 0; i < n; i++) {
        res += catalan(i) * catalan(n-i-1);
    }
    return res;
}
int main() {
        for (int i = 0; i <= 10; i++) {
            printf("%d - %ld\n", i, catalan(i));
        }

    return 0;
}
