#include <stdio.h>
#include <stdlib.h>

#define N 10

int stack[N];
int top = -1;

void push() {
	if (top == N-1)
		printf("Overflow condtion : Stack is full\n");
	else {
	     int x;
	     printf("Enter the data : ");
	     scanf("%d", &x);
             top++;
	     stack[top] = x;
	}
}

void pop() {
	if (top == -1)
	     printf("Underflow condition : Stack is Empty\n");
	else {
	     printf("Top element in Stack : %d\n", stack[top]);
	     top--;
	}
}

void peek() {
	if (top == -1)
             printf("Stack is Empty\n");
	else 
	     printf("Top element in Stack : %d\n", stack[top]);
}

void display() {
	if (top == -1)
             printf("Stack is Empty\n");
	else {
	     for (int i = top; i >= 0; i--) {
		   printf("%d -> ", stack[i]);
	     }
	     printf("Null\n");
	}
}


int main () {
     int ch;
     do {
	printf("============= Stack Operations by Array ===============\n"
		"1. Push() \n"
		"2. Pop() \n"
		"3. Peek() \n"
		"4. Display() \n"
		"5. Exit \n");

	printf("Enter the choice : ");
	scanf("%d", &ch);

	switch(ch) {
		case 1: 
		     push();
		     printf("Pushed the element to stack\n");
		     break;
		case 2:
		     pop();
		     printf("Pop the element from stack\n");
		     break;
                case 3:
		     peek();
		     printf("Picked top element from stack\n");
		     break;
		case 4:
		     printf("Stack Elements : ");
		     display();
		     break;
		case 5:
		     printf("Exiting...\n");
		     exit(1);
		default:
		     printf("Invalid choice\n");
	}
     }while (ch != 0);

     return 0;
}



