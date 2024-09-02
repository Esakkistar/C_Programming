#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define N 15
char post[N];
int postfix[N];
int top = -1;

void push(int n) {
	if (top == N-1) {
		printf("Stack is overflow\n");
		return;
	}
        postfix[++top] = n; 
}

int pop() {
	if (top == -1) {
		printf("Stack is underflow\n");
		return 1;
	}
	return postfix[top--];
}

void EvalutePostfix (char *expr) {
	int op1, op2, result;
	for (int i = 0; expr[i] != '\0'; i++) {
	        if ( isdigit(expr[i])) {
                     push(expr[i] - '0');
		}
		else {
		     op1 = pop();
		     op2 = pop();
		     printf("op1 : %d, op2 : %d\n",op1,op2);

		     switch(expr[i]) {
			   case '+':
				   result = op2 + op1;
				   printf("Result + : %d\n",result);
				   break;
		           
			   case '-':
				   result = op2 - op1;
				   break;
			   
			   case '*':
				   result = op2 * op1;
				   printf("Result * : %d\n",result);
				   break;
			   
			   case '/':
				   if (op1 == 0) {
					   printf("Division by Zero Erro\n");
					   return;
				   }
				   result = op2 / op1;
				   printf("Result / : %d\n",result);
				   break;
		             
			   case '%':
				   result = op2 % op1;
				   break;
		            
			   case '^':
				   result = op2 ^ op1;
				   break;
		           default:
				   printf("Invalid character in Expression\n");
				   return;
		     }

		     push(result);
		}
	}
}


int main() {
	printf("Enter the postfix Expression: ");
	fgets(post,10,stdin);
        EvalutePostfix(post);
	printf("Postfix Result : %d\n", pop());
	return 0;
}
		       




