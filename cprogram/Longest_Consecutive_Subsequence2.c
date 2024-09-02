#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

void print_array(int* arr,int n) {
	for (int i = 0; i< n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int longest_consecutive(int* a, int n) {
	int maxCount = 0, cnt = 0, val;
	int ele1[n], ele2[n], k, l;
	
	int* hash = (int*) calloc (MAX,sizeof(int));

	for(int i = 0; i < n; i++) {
		hash[a[i]] = 1;
	}

	for(int i = 0; i < n; i++) {
		val = a[i];
		cnt = 1;
		k = 0;
		ele1[k++] = val;

		while (val+1 < MAX && hash[val+1]) {
			val++;
			cnt++;
			ele1[k++] = val;
		}
		if (cnt > maxCount) {
			maxCount = cnt;
			l = 0;
			for (int i = 0; i < k; i++) {
				ele2[l++] = ele1[i];
			}
		}
	}
        printf("Longest Consective Elements : ");
	print_array(ele2,l);

	free(hash);

	return maxCount;
}



int main () {
	int N;
	printf("Enter the Array Size : ");
	scanf("%d", &N);

	int* arr = (int*) malloc (N*sizeof(int));


	srand(time(NULL));
	for(int i = 0; i < N; i++) {
		arr[i] = rand() % 50 + 1;
	}

	printf("Array : ");
	print_array(arr,N);

	int cnt = longest_consecutive(arr,N);

        printf("Longest subsequence of consecutive elements : %d\n", cnt);

	free(arr);
}


