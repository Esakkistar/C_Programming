/*
 * Count all combinations of coins to make a given value sum (Coin Change II)
Last Updated : 21 Jul, 2024
Given an integer array of coins[ ] of size N representing different types of denominations and an integer sum, the task is to count all combinations of coins to make a given value sum.

Note: Assume that you have an infinite supply of each type of coin.

Examples:

Input: sum = 4, coins[] = {1,2,3}
Output: 4
Explanation: there are four solutions: {1, 1, 1, 1}, {1, 1, 2}, {2, 2}, {1, 3}

Input: sum = 10, coins[] = {2, 5, 3, 6}
Output: 5
Explanation: There are five solutions:
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5} */

#include <stdio.h>

// Function to count the number of ways to make a given sum with the given coin denominations
int countCombinations(int coins[], int N, int sum) {
    int dp[sum + 1];

    // Initialize dp array to 0
    for (int i = 0; i <= sum; i++) {
        dp[i] = 0;
    }

    // There is one way to make sum 0: use no coins
    dp[0] = 1;

    // Iterate over each coin
    for (int i = 0; i < N; i++) {
        // Update the dp array for sums that can include this coin
        for (int j = coins[i]; j <= sum; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    // The answer is in dp[sum]
    return dp[sum];
}

int main() {
    int sum = 4;
    int coins[] = {1, 2, 3};
    int N = sizeof(coins) / sizeof(coins[0]);

    int result = countCombinations(coins, N, sum);
    printf("Number of combinations to make sum %d: %d\n", sum, result);

    // Test case 2
    sum = 10;
    int coins2[] = {2, 5, 3, 6};
    N = sizeof(coins2) / sizeof(coins2[0]);

    result = countCombinations(coins2, N, sum);
    printf("Number of combinations to make sum %d: %d\n", sum, result);

    return 0;
}

