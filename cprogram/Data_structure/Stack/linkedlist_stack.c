#include <stdio.h>
#include <stdlib.h>

typedef struct Stack_Node {
	int data;
	struct Stack_Node* next;
}Node;

Node* top = NULL;

void push() {
       int x;
       Node* new = (Node*) malloc(sizeof(Node));
       printf("Enter the data : ");
       scanf("%d", &new->data);
       
       new->next = top;
       top = new;
}

void pop() {
       if (top == NULL)
	     printf("Underflow Condition : Stack is Empty\n");
       else {
	     Node* temp = top;
	     printf("Top element in Stack : %d\n",temp->data);
	     top = temp->next;
	     free(temp);
       }
}

void peek() {
       if (top == NULL)
             printf("Stack is Empty\n");
       else 
	     printf("Top data in Stack : %d\n", top->data);
}
	
void display() {
       if (top == NULL)
             printf("Stack is Empty\n");
       else {
	     Node* temp = top;

	     while (temp) {
		     printf("%d -> ",temp->data);
		     temp = temp->next;
	     }
	     printf("NULL\n");
       }
}


int main () {
     int ch;
     do {
	printf("============= Stack Operations by LinkedList ===============\n"
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
