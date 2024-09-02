#include <stdio.h>
#include<string.h>


int power(int a, int b) {
	if (b == 0)
		return 1;
	if (b == 1) 
		return a;

	return power(a, b-1) * a;
}

int Atoi(char* s) {
	int val = 0;
        int len = strlen(s);

	for (int i = len-1; i >= 0; i--) {
		int n = s[i] - '0';
		if (n <= 9) 
			val += n * power(10, len-1-i);
		else return 0;
	}

	/* for (int i = 0; s[i] != '\0'; ++i)
        	val = val * 10 + s[i] - '0'; */

	return val;
}

void swap (char* a, char* b) {
	char t = *a;
	*a = *b;
	*b = t;
}
void reverse(char* s) {
	int n = strlen(s);
	int i = 0;
	int j = n-1;
	while (i < n/2) {
		swap(&s[i],&s[j--]);
		i++;
	}
	printf("s : %s, n : %d\n",s, n);
}
void Itoa(int t)  {
        char s[10];
	int i = 0;
	int n = t;
	while(n != 0) {
		s[i++] = (n % 10) + '0';
		n /= 10;
	}
	s[i] = '\0';
	reverse(s);
	printf("Equivalent Integer to String %d : %s\n", t, s);
}

int main () {
	char* s;
	printf("Enter the Integer string: ");
	scanf("%s", s);

	int val = Atoi(s);

	if (val) {
	      printf("Equivalent String to integer %s : %d\n", s, val);
	}
	else
	      printf("Invalid String for equivalent Integer\n");
	

	Itoa(50);
	int n;
	sscanf(s, "%d", &n); //integer to string
	printf("n : %d\n", n);
	int n2 = 20;
	sprintf(s, "%d", n2); //string to integer 
	printf("s : %s\n", s);

	return 0;
}

