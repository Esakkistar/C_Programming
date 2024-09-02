#include <stdio.h>
#include <stdlib.h>

typedef struct Queue_Node {
	int data;
	struct Queue_Node* next;
}Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue() {
       int x;
       Node* new = (Node*) malloc(sizeof(Node));
       printf("Enter the data : ");
       scanf("%d", &new->data);
       new->next = NULL;
       
       if (front == NULL && rear == NULL) {
	     front = rear = new;
	     rear->next = front;
       }
       else {
	     rear->next = new;
	     rear = new;
	     rear->next = front;
       }
}

void dequeue() {
       Node* temp = front;
       if (front == NULL && rear == NULL)
	     printf("Queue in Underflow Condition...\n");
       else if (front == rear) {
	       printf("Top element in Stack : %d\n",temp->data);
	       front = rear = NULL;
	       free(temp);
       }
       else {
	     printf("Top element in Stack : %d\n",temp->data);
	     front = temp->next;
	     rear->next = front;
	     free(temp);
       }
}

void peek() {
       if (front == NULL && rear == NULL)
             printf("Queue is Empty\n");
       else 
	     printf("Front data in Queue : %d\n", front->data);
}
	
void display() {
       if (front == NULL && rear == NULL)
             printf("Queue is Empty\n");
       else {
             Node* temp = front;
	     while (temp->next != front) {
		     printf("%d -> ",temp->data);
		     temp = temp->next;
	     }
	     printf("%d -> ",temp->data);
	     printf("NULL\n");
       }
}


int main () {
     int ch;
     do {
	printf("============= Circular Queue Operations by LinkedList ============ \n"
		"1. enqueue() \n"
		"2. dequeue() \n"
		"3. Peek() \n"
		"4. Display() \n"
		"5. Exit \n");

	printf("Enter the choice : ");
	scanf("%d", &ch);

	switch(ch) {
		case 1:
		     enqueue();
		     printf("Pushed the element to Queue\n");
		     break;
		case 2:
		     dequeue();
		     break;
                case 3:
		     peek();
		     break;
		case 4:
		     printf("Queue Elements : ");
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

