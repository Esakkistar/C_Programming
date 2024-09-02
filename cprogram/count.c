#include <stdio.h>
#include <stdlib.h>

void print_array(int* arr, int N) {
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void count_group(int* arr, int N) {
	int found[N];
	int count[N];
	int cnt, k = 0;

	for (int i = 0; i < N; i++) {
                found[i] = 0;
        }

	for (int i = 0; i < N-1; i++) {
		cnt = 1;
		for(int j = i+1; j < N; j++) {
			if (arr[i] == arr[j]) {
				found[j] = 1;
				cnt++;
			}
		}

		if (found[i] == 0) {
			count[k] = cnt;
			arr[k++] = arr[i];
		}
	}

	if (found[N-1] == 0) {
		count[k] = 1;
		arr[k++] = arr[N-1];
	}

        for (int i = 0; i < k; i++) {
		printf("%d - %d\n",arr[i],count[i]);
	}

	for (int i = 0; i < k-1; i++) {
                for(int j = i+1; j < k; j++) {
                        if (count[i] < count[j]) {
				int t = count[i];
				count[i] = count[j];
				count[j] = t;

				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}

	printf("Print Array Max count : \n");
	for (int i = 0; i < k; i++) {
                printf("%d - %d\n",arr[i],count[i]);
        }
}

int main () {
	int N;
	int* arr;

	printf("Enter the Number of Array Elements : ");
	scanf("%d",&N);

	arr = (int*) malloc (N * sizeof(int));

        printf ("Fill the array Elements : ");
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	print_array(arr,N);

	count_group(arr,N);

        printf ("Group Count array Elements : ");
	//print_array(arr,N);

	free(arr);

	return 0;
}
