/*
 * Best Time to Buy and Sell Stock II (infinite transactions allowed)
Last Updated : 26 Jun, 2024
Given an array prices[] of size N denoting the cost of stock on each day, the task is to find the maximum total profit if we can buy and sell the stocks any number of times.

Note: We can only sell a stock which we have bought earlier and we cannot hold multiple stocks on any day.

Examples:

Input: prices[] = {100, 180, 260, 310, 40, 535, 695}
Output: 865
Explanation: Buy the stock on day 0 and sell it on day 3 => 310 – 100 = 210
                       Buy the stock on day 4 and sell it on day 6 => 695 – 40 = 655
                       Maximum Profit  = 210 + 655 = 865

Input: prices[] = {4, 2, 2, 2, 4}
Output: 2
Explanation: Buy the stock on day 4 and sell it on day 5 => 4 – 2 = 2
                       Maximum Profit  = 2  */


// Importing the required header files
#include <stdio.h>

// Creating MACRO for finding the maximum number
#define max(x, y) (((x) > (y)) ? (x) : (y))

// Creating MACRO for finding the minimum number
#define min(x, y) (((x) < (y)) ? (x) : (y))

// Function that return
int maxProfit(int prices[], int size)
{

    // maxProfit adds up the difference between
    // adjacent elements if they are in increasing order
    int ans = 0;

    // The loop starts from 1
    // as its comparing with the previous
    for (int i = 1; i < size; i++) {
        // If the current element is greater than the
        // previous then the difference is added to the
        // answer
        if (prices[i] > prices[i - 1])
            ans += prices[i] - prices[i - 1];
    }

    return ans;
}

// Driver Code
int main()
{
    //int price[] = { 100, 180, 260, 310, 40, 535, 695 };
    int price[] = {4, 2, 2, 2, 4};
    int n = sizeof(price) / sizeof(price[0]);
    printf("Max profit - %d\n", maxProfit(price, n));
    return 0;
}
