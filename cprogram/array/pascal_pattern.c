#include <stdio.h>

int main () {
	int N;
	printf("Enter the Number : ");
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = i; j < N; j++) {
			printf(" ");
		}
                int p = 1;
		for (int k = 1; k <= i; k++) {
			printf("%d ",p);
			p = p * (i - k) / k;
		}
		printf("\n");
	}
        
	return 0;
}
