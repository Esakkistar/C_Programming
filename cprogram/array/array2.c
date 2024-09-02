#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int main () {
	int N,K;
	int cnt = 0;
	int hash[MAX];
	printf("No.of Array Elements: ");
	scanf("%d", &N);
	
	printf("Distance Between adjacent elements: " );
	scanf("%d", &K);

	int* A = (int*) malloc (N*sizeof(int));

	printf ("Fill Array A : ");
	for (int i = 0; i<N; i++){
		scanf("%d", &A[i]);
	}
        int t,flag;
	for (int i = 0; i < N-1; i++) {
		if ( A[i] - A[i+1] == K || A[i+1] - A[i] == K ) {
			cnt++;
			if (flag == 1) {
				cnt += t;
				flag = 0;
			}
		}
		else {
			flag = 1;
			t = 1;
		}
	}

	printf ("Count : %d \n", cnt);

	free(A);

	return 0;
}


