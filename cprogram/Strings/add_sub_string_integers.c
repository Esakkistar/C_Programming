#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

char* add_strings_integers (char* s1, char* s2) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int maxlen = len1 > len2 ? len1 : len2;
	
	int num1, num2;
	int carry = 0;
	int sum;

	char* add = (char*) malloc((maxlen+2) * sizeof(char));
	add[maxlen+1] = '\0';
	int index = 0;

	for (int i = 0; i < maxlen; i++) {
		num1 = i < len1 ? s1[len1-1-i] - '0' : 0;
		num2 = i < len2 ? s2[len2-1-i] - '0' : 0;

		sum = num1 + num2 + carry;
		add[maxlen-i] = (sum % 10) + '0';
		carry = sum / 10;
	}
	if (carry) {
		add[0] = '1';
		return add;
	}
	return add + 1;
}

char* sub_strings_integers(char* s1, char* s2) {
	int len1 = strlen(s1);
        int len2 = strlen(s2);
        int maxlen = len1 > len2 ? len1 : len2;

        int num1, num2;
        int borrow = 0;
        int diff;

        char* sub = (char*) malloc((maxlen+1) * sizeof(char));
        sub[maxlen] = '\0';
        int index = 0;

	for (int i = 0; i < maxlen; i++) {
                num1 = i < len1 ? s1[len1-1-i] - '0' : 0;
                num2 = i < len2 ? s2[len2-1-i] - '0' : 0;
               
		diff = num1 - num2 - borrow;

		if (diff < 0) {
			diff += 10;
			borrow = 1;
		}
		else {
			borrow = 0;
		}

		sub[maxlen-1-i] = diff + '0';
	}

	int i = 0;

	while(sub[i] == '0' && sub[i+1] != '\0') {
		i++;
	}

	return sub+i;
}

int main () {
	char s1[MAX];
	char s2[MAX];

	printf("Enter the first number: ");
	scanf("%s", s1);
    	printf("Enter the second number: ");
    	scanf("%s", s2);

	char* add = add_strings_integers(s1, s2);

	printf("Addtion %s + %s : %s\n", s1, s2, add);

	char* sub = sub_strings_integers(s1, s2);

        printf("Subtraction %s - %s : %s\n", s1, s2, sub);

	//free(add);
	//free(sub);

	return 0;
}
