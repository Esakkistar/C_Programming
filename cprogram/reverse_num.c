#include <stdio.h>

int main () {
	int N,t,s = 0;

	printf("Enter the Number : ");
	scanf("%d", &N);

	t = N;

	while (t) {
		s = s * 10 + (t%10);
		t = t /10;
	}
	
	printf("Reverse the Number : %d\n",s);

	return 0;
}






