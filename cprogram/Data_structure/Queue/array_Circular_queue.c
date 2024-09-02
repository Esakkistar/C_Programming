#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5

int queue[N];
int front = -1, rear = -1;

void enqueue () {
     int n;
     printf("Enter the element you wants add to queue : ");
     scanf("%d",&n);
     
     if (front == -1 && rear == -1) {
	     front = rear = 0;
	     queue[front] = n;
     }
     else if ( (rear+1) % N == front) {
	     printf("Queue is Full\n");
     }
     else {
	     rear = (rear+1) % N;
	     queue[rear] = n;
     }
}

void dequeue () {
    if(front == -1 && rear == -1) {
	    printf("Queue in Underflow Condition...\n");
    }
    else if (front == rear) {
	    printf("Front element in Queue : %d\n", queue[front]);
	    front = rear = -1;
    }
    else {
	    printf("Front Element in Queue : %d\n", queue[front]);
	    front = (front+1) % N;
    }
}

void display () {
    int i = front;
    if(front == -1 && rear == -1) {
            printf("Queue is Empty...\n");
    }	
    else {
	   while(i != rear) {
		   printf("%d -> ",queue[i]);
		   i = (i+1) % N;
	   }
	   printf("%d -> ",queue[i]);
	   printf("NULL \n");
    }
}

void peek () {
   if(front == -1 && rear == -1) {
           printf("Queue is Empty...\n");
   }
   else {
	   printf("Front element in Queue : %d\n", queue[front]);
   }
}

int main () {
     int ch;
     do {
	printf("============= Circular Queue Operations by Array ===============\n"
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
		     printf("Add the element to Queue\n");
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
