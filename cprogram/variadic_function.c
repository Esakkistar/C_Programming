#include <stdio.h>
#include <stdarg.h>

void sum (int c, ... ) {
	int sum = 0;
	va_list arg;
	va_start (arg,c);

	for (int i = 1;i <= c; i++) {
		sum += va_arg(arg,int);
	}
	printf("Sum = %d\n",sum);
}

void min_max(int c, ... ) {
	if (c == 0) {
		printf("No arguments...\n");
		return ;
	}
	int min,max,num;
	
	va_list arg;
	va_start(arg,c);

	min = va_arg(arg,int);
	max = min;

	printf("Count : %d,min : %d\n",c,min);

	for (int i = 1;i < c; i++) {
		int num = va_arg(arg,int);
		if(num < min)
			min = num;
		if(num > max)
			max = num;
	}

        printf("Min : %d, Max : %d\n",min,max);

}

int main () {
	sum (7,11,22,33,2,45,16,76);
	min_max(8,3,11,22,33,2,45,16,76);
	return 0;
}
