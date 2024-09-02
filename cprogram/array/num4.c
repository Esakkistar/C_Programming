#include <stdio.h>

int main () {
	//int arr[] = {1, 4, 3, 2, 6, 7};
	int arr[] = {1, 3, 5, 8, 6, 2, 6, 7, 6, 8, 9, 4, 5};

	int N = sizeof(arr) / sizeof(arr[0]);

	
	int i = 0, num = 0;
        int flag = 0;
	int jump = 0;
	while (flag == 0) {
		num = arr[i];
		if (num >= N-i-1) {
			jump++;
			flag = 1;
		}
		else {
			i = i + num;
			jump++;
		}
	}
	printf ("Jump : %d\n", jump);
			

	return 0;
}

