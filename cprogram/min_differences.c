/*
 * Minimize the maximum difference between the heights
Given the heights of N towers and a value of K, Either increase or decrease the height of every tower by K (only once) where K > 0. After modifications, the task is to minimize the difference between the heights of the longest and the shortest tower and output its difference.

Examples:

Input: arr[] = {1, 15, 10}, k = 6
Output:  Maximum difference is 5.
Explanation: Change 1 to 7, 15 to 9 and 10 to 4. Maximum difference is 5 (between 4 and 9). We can’t get a lower difference.

Input: arr[] = {1, 5, 15, 10}, k = 3
Output: Maximum difference is 8, arr[] = {4, 8, 12, 7} */

#include <stdio.h>
#include <stdlib.h>

void print_array (int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

// Function to compare two integers, used for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to find the minimum difference
int minimize_difference(int heights[], int N, int K) {
    // If there is only one tower, the difference is always 0
    if (N == 1) {
        return 0;
    }

    // Sort the heights array
    qsort(heights, N, sizeof(int), compare);

    // Initialize minimum difference to a large value
    int min_diff = heights[N - 1] - heights[0];
    
    // Iterate over the array to calculate minimum difference after modifications
    for (int i = 0; i < N - 1; i++) {
        int min_possible = (heights[0] + K < heights[i + 1] - K) ? (heights[0] + K) : (heights[i + 1] - K);
        int max_possible = (heights[N - 1] - K > heights[i] + K) ? (heights[N - 1] - K) : (heights[i] + K);
        int diff = max_possible - min_possible;
        if (diff < min_diff) {
            min_diff = diff;
        }
    }

    return min_diff;
}

int min_diff (int* h, int n, int k) {
	int height[n];
	qsort(h, n, sizeof(int), compare);
	print_array(h,n);
	for (int i = 0; i < n; i++) {
		if (h[i] < 10 )
			height[i] = h[i] + k;
		else
			height[i] = h[i] - k;
	}
	print_array(height,n);

	return height[n-1] - height[0];
}

int main() {
    int N, K;

    // Input number of towers and K
    printf("Enter the number of towers: ");
    scanf("%d", &N);
    printf("Enter the value of K: ");
    scanf("%d", &K);

    int *heights = (int *)malloc(N * sizeof(int));

    // Input the heights of the towers
    printf("Enter the heights of the towers:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &heights[i]);
	//heights[i] = rand() % 20 + 1;
    }

    // Calculate the minimum difference
    int result = minimize_difference(heights, N, K);

    // Output the result
    printf("The minimum difference is: %d\n", result);

    int r = min_diff(heights, N, K);
    printf("The minimum diff is: %d\n", r);

    // Free allocated memory
    free(heights);

    return 0;
}

