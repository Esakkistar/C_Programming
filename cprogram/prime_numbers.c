/* Print N prime numbers ending with k dight. add 2 & 5 is staring array elements and print in ascending order */

#include <stdio.h>
#include <stdlib.h>

int main () {
	int N,k;
	
	printf("Enter Total No.of Prime Numbers you want : ");
	scanf("%d", &N);

	printf("Ending Prime Number digit is : ");
	scanf("%d", &k);

	int *arr = (int*)malloc((N+2) * sizeof(int));
	
	arr[0] = k;
	
	int n = k+1;
	int j = 1;
	int flag = 0;
	int t = 1;
	
	
	while (t < N) {
	    if (n % 10 == k) {
		
			for (int i = 2; i <= n/2; i++ ) {
				if (n % i == 0) {
					flag = 1;
					break;
				}
			}

			if (flag == 0) {
				arr[j++] = n;
				t++;
			}
		}
		n++;
		flag = 0;
	}
	printf("J : %d\n", j);

	printf ("Prime Numbers : ");

	for (int i = 0; i < N; i++) {
		printf ("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}




