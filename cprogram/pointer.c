#include <stdio.h>

void func (int *p1, int *p2) {
	int a = 50;
	*p1 = 30;
	*p2 = 40;
	// p2 = &a;   Not valid.
}

int main () {
	int a = 10;
	int b = 20;

	int *p1 = &a;
	int *p2 = &b;

	printf("Before ->  p1 : %d, p2 : %d\n",*p1,*p2);

	func(p1,p2);
	
	printf("After ->  p1 : %d, p2 : %d\n",*p1,*p2);

	return 0;

}


