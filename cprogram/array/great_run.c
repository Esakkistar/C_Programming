/*
 * The Great Run

Vishal loves running. He often visits his favourite Nehru Park and runs for very long distances. On one such visit he found that the number of girls in the park was unusually high. Now he wants to use this as an opportunity to impress a large number of girls with his awesome speed.

The track on which he runs is an N kilometres long straight path. There are a[i] girls standing within the ith kilometre of this path. A girl will be impressed only if Vishal is running at his maximum speed when he passes by her. But he can run at his best speed only for a single continuous stretch of K kilometres. Now Vishal wants to know what is the maximum number of girls that he can impress.

Input
First line of the input contains the number of testcases T.

For each test case,

First line contains two space-separated integers N and K, the length of the track and the maximum distance he can run at his best speed.

Second line contains N space-separated integers, the number of girls within each kilometre of the track.

Output
For each test case print one line containing an integer, denoting the maximum number of girls Vishal can impress.

Sample 1:
Input
1
7 2
2 4 8 1 2 1 8

Output:
12

Initial Window (first 2 kilometers): [2,4]

[2,4] with a sum of 6.
Sliding the Window:
Window [4, 8]: sum is 12.
Window [8, 1]: sum is 9.
Window [1, 2]: sum is 3.
Window [2, 1]: sum is 3.
Window [1, 8]: sum is 9.
The maximum sum encountered is 12. */

#include <stdio.h> 
#include <stdlib.h>

int main () {
	int T, N, K;

	printf("Enter the No.of TestCases : ");
	scanf("%d", &T);

	while (T) {
		printf("No.of Array Elements: ");
		scanf("%d", &N);

		printf("Enter Maximum distance he can run at his best speed: ");
                scanf("%d", &K);

		int* arr = (int*) malloc (N*sizeof(int));

		printf ("Fill Array : ");
		for (int i = 0; i<N; i++){
			scanf("%d", &arr[i]);
		}
		printf("\n");
               
		int max = 0;
		int r1[10], r2[10];
		for (int i = 0; i < N; i++) {
			int j = i;
			int t = 0, sum = 0;
                        
			while (t < K) {
				if (j < N) {
                                      r1[t] = j;
				      sum += arr[j++];
				      t++;
				}
				else {
				      break;
				}
			}

			if (t == K && sum > max) {
				max = sum;
				for (int i = 0; i < K; i++) {
					r2[i] = r1[i];
				}
			}
		}
		printf("Girls | Kilometer\n");
		for (int i = 0; i < K; i++) {
			printf("%d   %d\n", arr[r2[i]],r2[i]);
		}
		printf("\n");
                                    
	        printf("Maximum number of girls Vishal impressed : %d\n", max);
		T--;
		free(arr);
	}

	return 0;
}
