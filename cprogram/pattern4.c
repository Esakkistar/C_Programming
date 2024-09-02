#include <stdio.h>

int main () {
	int N;
	printf("Enter the Number : ");
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = i; j < N; j++) {
			printf(" ");
		}

		for (int k = 1; k <= 2*i-1; k++) {
			printf("*");
		}
		printf("\n");
	}
        
	for (int i = 2; i <= N; i++) {
                for (int j = 1; j < i; j++) {
                        printf(" ");
                }

                for (int k = i; k <= 2*N-i; k++) {
                        printf("*");
                }
		printf("\n");
        }

	return 0;
}
