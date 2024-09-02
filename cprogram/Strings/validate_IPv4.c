#include <stdio.h>
#include<string.h>

#define MAX 4

int Atoi(char* s) {
	int val = 0;
        int len = strlen(s);

	for (int i = 0; s[i] != '\0'; i++) {
		int n = s[i] - '0';
                if (n <= 9)
			val = val * 10 + n ; 
		else return 0;
	}

	if (val <= 255) return 1;
	else return 0;
}

int validate_Ipv4 (char* s) {
	char str[50];
	strcpy(str, s);

	char* sub = strtok(str, ".");
	int t = 0;
	while (sub) {
		if (Atoi(sub) && t < MAX) {
			sub = strtok(NULL, ".");
			t++;
		}
		else return 0;
	}
	
        if (t == MAX) return 1;
        else return 0;
}

int main () {
	char* s;
	printf("Enter the IPv4 Address : ");
	scanf("%s", s);

	int val = validate_Ipv4(s);

	if (val) {
	      printf("Valid IPv4 address : %s\n", s);
	}
	else
	      printf("Invalid IPv4 address\n");


	return 0;
}

