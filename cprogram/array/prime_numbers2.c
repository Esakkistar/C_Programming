#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Isprime(int n) {
	if (n % 2 == 0) return 0;
	for (int i = 3; i <= n/2; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main () {
	int N,k;

        printf("Enter Total No.of Prime Numbers you want : ");
        scanf("%d", &N);

        printf("Ending Prime Number digit is : ");
        scanf("%d", &k);

        int *arr = (int*)malloc((N)*sizeof(int)); 


	int c = 0;

	int n = 0, j = 0;
	while (c < N) {
		n++;

		if (n % 2 == 0) continue;

		if (n % 10 == k && Isprime(n)) {
			arr[j++] = n;
			c++;
		}
	}

	printf("Prime Numbers %d -> : ", c);
	for (int i = 0; i < j; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);

	return 0;
}




