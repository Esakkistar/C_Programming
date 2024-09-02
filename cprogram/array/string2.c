#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void change(char s[]) {
	strcpy (s, "Esakki");
}

int main () {
	char s1[50];
	char s2[50];
	char* s3;

	printf("Enter s1 : ");
	scanf("%s", s1);

	strcpy (s2,s1);
	
	printf("Before : s1 -%s, s2 - %s\n",s1,s2 );

	change(s2);
	
	printf("After : s1 -%s, s2 - %s\n",s1,s2 );

	s3 = (char*)malloc(50 * sizeof(char));
	s3 = "Surya";

	strcpy (s2,s3);

        printf("Before : s2 -%s, s3 - %s\n",s2,s3 );
	change(s2);
        printf("After : s2 -%s, s3 - %s\n",s2,s3 );

	return 0;
}
