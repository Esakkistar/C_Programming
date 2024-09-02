#include <stdio.h>
#include <string.h>

int main () {
	char s[10];
	printf("Enter the string : ");
	fgets(s,10,stdin);
        
	int len = strlen(s);
	printf("String len : %d\n",len);

	for (int i = 0; i < len-1; i++ ) { 

		/*for (int space = 0; space < (len-1-i); space++ ) 
			printf(" ");*/
		for (int j = 0; j < len-i-1; j++ )
                        printf(" ");
                
		for ( int j = 0; j <= i; j++)
			printf("%c",s[j]);

		for (int k = i-1; k >= 0; k--)
			printf("%c",s[k]);

		printf("\n");
	}

	/*for (int i = 0; i < len; i++ ) {
		for (int j = 0; j < len-1; j++ ) 
			printf(" ");
		printf()*/

	return 0;
}

		

