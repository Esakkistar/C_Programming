#include <stdio.h>

void fun(int *p) {
	*p = 10;
	++*p;
}
int main () {
	int a = 5;
	int* ptr = &a;
	printf("Before Ptr : %d - %d\n",*ptr,a);
        fun(&a);
	printf("After Ptr : %d - %d\n",*ptr,a);
	return 0;
}

