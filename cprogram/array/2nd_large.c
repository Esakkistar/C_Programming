#include<stdio.h>

#define N 10

int main () {
        int arr[N],ascen[N],decen[10];
        int n;
        printf("Enter array size : ");
        scanf("%d",&n);

        for (int i = 0; i<n; i++) {
                scanf("%d",&arr[i]);
        }

	int max = arr[0];
	int sec_max = arr[0];
	int min = arr[0];
	int sec_min = arr[0];
	int temp;

	for (int i = 0; i < n; i++) {
		if (sec_max < arr[i]) {
			sec_max = arr[i];
		}
		if (sec_max > max) {
			temp = max;
			max = sec_max;
			sec_max = temp;
		}
		if (sec_min > arr[i]) {
			sec_min = arr[i];
		}
		if (sec_min < min) {
			temp = min;
			min = sec_min;
			sec_min = temp;
		}
	}

	printf("Large : %d, 2nd_large : %d\n",max,sec_max);
	printf("Small : %d, 2nd_small : %d\n",min,sec_min);

	return 0;
}
