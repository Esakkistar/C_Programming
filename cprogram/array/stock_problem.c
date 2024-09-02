/*
 * The Stock Span Problem
The stock span problem is a financial problem where we have a series of N daily price quotes for a stock and we need to calculate the span of the stock’s price for all N days. The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day. 

Examples:

Input: N = 7, price[] = [100 80 60 70 60 75 85]
Output: 1 1 1 2 1 4 6
Explanation: Traversing the given input span for 100 will be 1, 80 is smaller than 100 so the span is 1, 60 is smaller than 80 so the span is 1, 70 is greater than 60 so the span is 2 and so on. Hence the output will be 1 1 1 2 1 4 6.

Input: N = 6, price[] = [10 4 5 90 120 80]
Output:1 1 2 4 5 1
Explanation: Traversing the given input span for 10 will be 1, 4 is smaller than 10 so the span will be 1, 5 is greater than 4 so the span will be 2 and so on. 
Hence, the output will be 1 1 2 4 5 1.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 30

void print_array(int* arr,int n) {
	for (int i = 0; i< n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main () {
	int N, span[MAX];
	printf("Enter the Array Size : ");
	scanf("%d", &N);

	int* arr = (int*) malloc (N*sizeof(int));

	srand(time(NULL));
	for(int i = 0; i < N; i++) {
		//arr[i] = rand() % 50 + 1;
		scanf("%d", &arr[i]);
	}
        
	int t = 0;
	for (int i = 0; i < N; i++) {
               
		while (t >= 0 && arr[t] <= arr[i]) {
			t--;
		}

		span[i] = (i == 0) ? 1 : i - t;
		t = i;
	}
	
	print_array (span,N);
	free(arr);

	return 0;
}

/*
 * #include <stdio.h>
   #include <stdlib.h>

// Function to calculate stock span
void calculateSpan(int price[], int N, int span[]) {
    // Stack to store indices of days
    int *stack = (int *)malloc(N * sizeof(int));
    int top = -1;

    for (int i = 0; i < N; i++) {
        // Calculate span for price[i]
        while (top >= 0 && price[stack[top]] <= price[i]) {
            top--;
        }
        // If stack is empty, it means the current price is higher than all previous prices
        span[i] = (top == -1) ? (i + 1) : (i - stack[top]);
        // Push this day's index onto the stack
        stack[++top] = i;
    }

    // Free the allocated memory
    free(stack);
}

int main() {
    int price1[] = {100, 80, 60, 70, 60, 75, 85};
    int N1 = sizeof(price1) / sizeof(price1[0]);
    int span1[N1];

    int price2[] = {10, 4, 5, 90, 120, 80};
    int N2 = sizeof(price2) / sizeof(price2[0]);
    int span2[N2];

    // Calculate spans
    calculateSpan(price1, N1, span1);
    calculateSpan(price2, N2, span2);

    // Print the results
    printf("Span for price1: ");
    for (int i = 0; i < N1; i++) {
        printf("%d ", span1[i]);
    }
    printf("\n");

    printf("Span for price2: ");
    for (int i = 0; i < N2; i++) {
        printf("%d ", span2[i]);
    }
    printf("\n");

    return 0;
}
*/
		

