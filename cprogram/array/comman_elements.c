/*
 * Maximum Common Elements Given two arrays A and B, each of size N, where each array consists of distinct elements.

   Find the number of elements that are common in both the arrays. */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void print_common(int* a, int* b, int n) {
	int* hashA = (int*) calloc (50, sizeof(int));

	int* hashB = (int*) calloc (50, sizeof(int));

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		hashA[a[i]] = 1;
		hashB[b[i]] = 1;
	}
	printf("Comman Elements in Array A & B : ");
	for (int i = 0; i < 50; i++) {
		if (hashA[i] && hashB[i])
			printf ("%d ", i);
	}
	printf("\n");

	free(hashA);
	free(hashB);
}

          
		
int main () {
	int T, N, K;

	printf("Enter the No.of TestCases : ");
	scanf("%d", &T);

	while (T) {
		printf("No.of Array Elements: ");
		scanf("%d", &N);

		int* A = (int*) malloc (N*sizeof(int));
		int* B = (int*) malloc (N*sizeof(int));

		srand(time(NULL));
		for (int i = 0; i<N; i++){
			//scanf("%d", &A[i]);
			A[i] = rand() % 50;
		}

                for (int i = 0; i<N; i++){
                        //scanf("%d", &B[i]);
			B[i] = rand() % 50;
                }

		print_array(A,N);
		print_array(B,N);
		print_common(A,B,N);

                int cnt = 0;
		int t[10];
		for (int i = 0; i < N; i++) {
			int flag = 0;
			for (int j = 0; j < cnt; j++) {
				if (A[i] == t[j]) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				for (int k = 0; k < N; k++) {
					if (A[i] == B[k]) {
						t[cnt++] = A[i];
						break;
					}
				}
			}
		}
		printf(" %d Comman Elements in Array A & B : ",cnt);
		for (int i = 0; i < cnt; i++){
                        printf("%d ", t[i]);
                }
		printf("\n");
		free(A);
		free(B);
		T--;
	}

	return 0;
}




