#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 256

void findfreq(char *str) {
	int freq[MAX] = {0};
	int len = strlen(str);

	for (int i = 0; i < len; i++) {
		if ( str[i] != ' ' && str[i] != '\n' ) {
			char s = tolower(str[i]);
			freq[(unsigned char)s]++;
		}
	}
	printf("Character | Frequency\n");
        printf("----------------------\n");
	for (int i = 0; i < MAX; i++) {
		if (freq[i] != 0) {
			printf("%c   | %d \n",i, freq[i]);
		}
	}
}


int main () {
	char str[MAX];

	printf("Enter the string : ");
	fgets(str,MAX,stdin); 
        
	int i = strcspn(str, "\n");
	str[i] = '\0';

        printf("Given String : %s\n",str);
	findfreq(str);

	return 0;
}

