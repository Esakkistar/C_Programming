#include <stdio.h>
#include <stdlib.h>

// Function to compare integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    int T, N;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &N);

        int *A = (int*) malloc (N * sizeof(int));
        int *B = (int*) malloc (N * sizeof(int));

        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        for (int i = 0; i < N; i++) {
            scanf("%d", &B[i]);
        }

        // Sort both arrays
        qsort(A, N, sizeof(int), compare);
        qsort(B, N, sizeof(int), compare);

        // Two pointer technique to count common elements
        int i = 0, j = 0, cnt = 0;
        while (i < N && j < N) {
	    if (A[i] == A[i+1]) {
		    i++;
		    continue;
	    }
	    if (B[j] == B[j+1]) {
                    j++;
                    continue;
            }
            if (A[i] == B[j]) {
                cnt++;
                i++;
                j++;
            } else if (A[i] < B[j]) {
                i++;
            } else {
                j++;
            }
        }

        printf("Count : %d\n", cnt);

        free(A);
        free(B);
    }

    return 0;
}
