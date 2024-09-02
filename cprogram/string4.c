#include <stdio.h>

int main() {
	char *str = "Esakki";
        unsigned int hash = 0;
	while (*str) {
		hash = (hash << 5) + *str++;
		printf("%d\n", hash);
	}

	printf(" Div : %d, Mod : %d\n", -15/10, -15 % 10);
	return 0;
}
