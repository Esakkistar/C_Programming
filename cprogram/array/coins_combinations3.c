/*
 * Coin Change – Minimum Coins to Make Sum
Last Updated : 13 Aug, 2024
Given an array coins[] of size N and a target value sum, where coins[i] represents the coins of different denominations. You have an infinite supply of each of coins. The task is to find minimum number of coins required to make the given value sum. If it’s not possible to make a change, print -1.

Examples:

Input: coins[] = {25, 10, 5}, sum = 30
Output: 2
Explanation : Minimum 2 coins needed, 25 and 5

Input: coins[] = {9, 6, 5, 1}, sum = 19
Output: 3
Explanation: 19 = 9 + 9 + 1

Input: coins[] = {5, 1}, sum = 0
Output: 0
Explanation: For 0 sum, we do not need a coin

Input: coins[] = {4, 6, 2], sum = 5
Output: -1
Explanation: Not possible to make the given sum. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_array(int* c, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");
}

void combinations(int* c, int size, int sum, int* comb, int csize, int start, int *min) {
    if (sum == 0) {
        if (csize < *min) {
            print_array(comb, csize);
            *min = csize;
        }
        return;
    }

    if (sum < 0) {
        return;
    }

    for (int i = start; i < size; i++) {
        comb[csize] = c[i];
        combinations(c, size, sum - c[i], comb, csize+1, i, min);
    }
}
int main() {
        int coins[] = {9, 6, 5};
        int n = sizeof(coins) / sizeof(int);
        int min = n+1;
        int sum = 19;
        int *comb = (int*) malloc(sum * sizeof(int));
        combinations(coins, n, sum,  comb, 0, 0, &min);

        printf("Min Coins : %d\n", min);
	
	free(comb);
        return 0;
}
