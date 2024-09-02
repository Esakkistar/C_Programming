#include <stdio.h>
#include <string.h>

#define N 100

void findfrequency(char *str, int len) {
	int freq[len];
	int mark = -1;
	int count;

	for (int i = 0; i < len; i++) {
		count = 1;
		for(int j = i+1; j < len; j++) {
			if (str[i] == " ")
				continue;
			if (str[i] == str[j]) {
				count++;
				freq[j] = mark;
			}
		}
		if (freq[i] != mark) {
			freq[i] = count;
		}
	}
	printf("Char   |   Count   \n");
	for (int i = 0; i < len; i++) {
		if (freq[i] != mark) {
			printf("%c      |  %d\n",str[i],freq[i]);
		}
	}
}



int main () {
	char str[N];
	printf("Enter the string : ");
	fgets(str,N,stdin);

	int len = strlen(str);

	printf("String : %s\n", str);

	findfrequency(str,len);

	return 0;
}
