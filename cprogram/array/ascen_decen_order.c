#include <stdio.h>
#include <string.h>

#define N 10

void ascending (int arr[], int n) {
	int temp;
        for (int i = 0; i < n-1; i++) {
                for(int j =i+1; j < n; j++) {
                        if(arr[i] > arr[j]) {
                                temp = arr[j];
                                arr[j] = arr[i];
                                arr[i] = temp;
                        }
                }
        }
}

void decending (int arr[], int n) {
        int temp;
        for (int i = 0; i < n-1; i++) {
                for(int j =i+1; j < n; j++) {
                        if(arr[i] < arr[j]) {
                                temp = arr[j];
                                arr[j] = arr[i];
                                arr[i] = temp;
                        }
                }
        }
}

int main () {
	int arr[N],ascen[N],decen[10];
	int n;
	printf("Enter array size : ");
	scanf("%d",&n);

	for (int i = 0; i<n; i++) {
		scanf("%d",&arr[i]);
	}

        ascending(arr,n);

	printf("Ascending Order : ");
	for (int i = 0; i<n; i++) {
                printf("%d ",arr[i]);
        }
        printf("\n");
	
        decending(arr,n);

	printf("Decending Order : ");
	for (int i = 0; i<n; i++) {
                printf("%d ",arr[i]);
        }
        printf("\n");
	return 0;

}




