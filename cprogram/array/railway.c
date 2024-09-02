/* Minimum Number of Platforms Required for a Railway/Bus Station
Last Updated : 05 Jul, 2024
We are given two arrays that represent the arrival and departure times of trains, the task is to find the minimum number of platforms required so that no train waits.

Examples: 

Input: arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00}, dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00} 
Output: 3 
Explanation: There are at-most three trains at a time (time between 9:40 to 12:00)

Input: arr[] = {9:00, 9:40}, dep[] = {9:10, 12:00} 
Output: 1 
Explanation: Only one platform is needed. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum number of platforms required
int findMinPlatforms(int arr[], int dep[], int n) {
    // Sort arrival and departure arrays
    qsort(arr, n, sizeof(int), (int (*)(const void*, const void*)) strcmp);
    qsort(dep, n, sizeof(int), (int (*)(const void*, const void*)) strcmp);

    // Initialize pointers and counters
    int platforms_needed = 1;
    int max_platforms = 1;
    int i = 1, j = 0;

    // Traverse the arrival and departure arrays
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            // New train is arriving before or when the previous one departs
            platforms_needed++;
            i++;
            if (platforms_needed > max_platforms) {
                max_platforms = platforms_needed;
            }
        } else {
            // Train has departed, so decrease the count of platforms needed
            platforms_needed--;
            j++;
        }
    }

    return max_platforms;
}

int main() {
    // Example input
    int arr1[] = {900, 940, 950, 1100, 1500, 1800};
    int dep1[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {900, 940};
    int dep2[] = {910, 1200};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("Minimum platforms required for first example: %d\n", findMinPlatforms(arr1, dep1, n1));
    printf("Minimum platforms required for second example: %d\n", findMinPlatforms(arr2, dep2, n2));

    return 0;
}
