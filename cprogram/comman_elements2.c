#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int main () {
	int N;
	int cnt = 0;
	int hash[MAX];
	printf("No.of Array Elements: ");
	scanf("%d", &N);

	int* A = (int*) malloc (N*sizeof(int));
	int* B = (int*) malloc (N*sizeof(int));

	printf ("Fill Array A : ");
	for (int i = 0; i<N; i++){
		scanf("%d", &A[i]);
	}
	printf ("Fill Array B : ");
	for (int i = 0; i<N; i++){
		scanf("%d", &B[i]);
	}

	for (int i = 0; i < MAX; i++) {
		hash[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		hash[A[i]] = 1;
	}

	for (int i = 0; i<N; i++) {     
		if (hash[B[i]]) {
			cnt++;
			//hash[B[i]] = 0;
		}
	}

	printf("Count : %d\n", cnt);

	free(A);
	free(B);

	return 0;
}

