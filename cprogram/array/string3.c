#include <stdio.h>

#define MAX 50

void mystrcat (char* d, char* s) {

	while(*d) {
		d++;
	}
	*d++ = ' ';

	while(*s) {
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
}


int main () {
	char dest[MAX] = "Esakki";
	char src[MAX] = "Babu";

	mystrcat(dest,src);
	printf("StrCat : %s\n",dest);

	return 0;

}

