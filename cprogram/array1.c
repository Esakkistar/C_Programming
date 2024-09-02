#include <stdio.h>
#include <stdlib.h>

int main () {
	int N,B;
	
	printf("Enter the No.of array Elements : ");
	scanf("%d", &N);
	
	int* arr = (int*) malloc(N*sizeof(int));

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	printf("Array Elements : ");
	for (int i = 0; i < N; i++) {
	       printf("%d ", arr[i]);
	}
	printf("\n");
	
	printf("Enter the number : ");
	scanf("%d", &B);
        
	int flag = 0;
	for (int i = 0; i < N-1; i++) {
		for (int j = i+1; j < N; j++) {
			if ( arr[i] - arr[j] == B ) {
				printf("%d - %d = %d \n", arr[i],arr[j],B);
				flag = 1;
			}	
			else if ( arr[j] - arr[i] == B ) {
				printf("%d - %d = %d \n", arr[j],arr[i],B);
                                flag = 1;
			}
		}
		if (flag == 1)
			break;
	}

	return 0;
}
				





	
