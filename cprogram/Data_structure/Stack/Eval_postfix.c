#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define N 15
char post[N];
int postfix[N];
int top = -1;

int main() {
	int op1, op2, result;
	printf("Enter the postfix Expression: ");
	fgets(post,10,stdin);

	for (int i = 0; post[i] != '\0'; i++) {
		if ( isdigit(post[i])) { 
		    postfix[++top] = post[i] - '0';
		}
		else {
		     op1 = postfix[top--];
		     op2 = postfix[top--];
		     printf("op1 : %d, op2 : %d\n",op1,op2);

		     switch(post[i]) {
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
					   return -1;
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
				   return -1;
		     }

		     postfix[++top] = result;
		}
	}

	printf("Postfix Result : %d\n", postfix[top]);
	return 0;
}
		       




