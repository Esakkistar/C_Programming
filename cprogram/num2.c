#include <stdio.h>
#include <string.h>

int main () {
	int n;
	int t, ret, sum = 0;
	printf("Enter the 5 digit Number : ");
	scanf("%d", &n);
        	
	t = n;
	while(t) {
	   ret = t % 10;
	   sum += ret;
	   t = t/10;
	}

	printf("Sum of 5 digit Number : %d\n",sum);

	return 0;

}





