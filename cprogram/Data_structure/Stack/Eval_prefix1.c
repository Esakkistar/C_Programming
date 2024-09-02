#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define N 15
char pre[N];
int prefix[N];
int top = -1;

void push(int n) {
	if (top == N-1) {
		printf("Stack is overflow\n");
		return;
	}
        prefix[++top] = n; 
}

int pop() {
	if (top == -1) {
		printf("Stack is underflow\n");
		return 1;
	}
	return prefix[top--];
}

void EvalutePrefix (char *expr) {
	int op1, op2, result;
	for (int i = strlen(pre) - 1; i >= 0; i--) {
	        if ( isdigit(expr[i])) {
                     push(expr[i] - '0');
		}
		else {
		     op1 = pop();
		     op2 = pop();
		     printf("op1 : %d, op2 : %d\n",op1,op2);

		     switch(expr[i]) {
			   case '+':
				   result = op1 + op2;
				   printf("Result + : %d\n",result);
				   break;
		           
			   case '-':
				   result = op1 - op2;
				   break;
			   
			   case '*':
				   result = op1 * op2;
				   printf("Result * : %d\n",result);
				   break;
			   
			   case '/':
				   if (op2 == 0) {
					   printf("Division by Zero Erro\n");
					   return;
				   }
				   result = op1 / op2;
				   printf("Result / : %d\n",result);
				   break;
		             
			   case '%':
				   result = op1 % op2;
				   break;
		            
			   case '^':
				   result = op1 ^ op2;
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
	printf("Enter the prefix Expression: ");
	fgets(pre,10,stdin);
        EvalutePrefix(pre);
	printf("Postfix Result : %d\n", pop());
	return 0;
}
		       




