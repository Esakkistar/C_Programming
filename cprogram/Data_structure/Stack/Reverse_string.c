#include <stdio.h>
#include <string.h>

#define N 20

char rev_str[N];
int top = -1;

void push(char ch) {
	if (top == N-1) {
	      printf("Stack is overflow\n");
	      return;
	}
	rev_str[++top] = ch;
}

char pop () {
	if (top == -1) {
	      printf("Stack is Underflow\n");
	      return 1;
	}
	return rev_str[top--];
}

int main () {        
        char str[N];
        printf("Enter the string : ");
	fgets(str,20,stdin);
	str[strcspn(str, "\n")] = '\0';  // Remove trailing newline
	int len = strlen(str);
	//scanf("%s",str);

	for (int i = 0;  i < len; i++) {
		push(str[i]);
	}
	for (int i = 0;  i < len; i++) {
                str[i] = pop();
	}
        
        printf("Reverse String : %s\n",str);

	return 0;
}
