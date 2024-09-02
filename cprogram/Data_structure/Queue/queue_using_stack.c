#include <stdio.h>
#include <stdlib.h>

#define N 5

int s1[N], s2[N];
int top1 = -1, top2 = -1;
int count = 0;

void push1(int n) {
	if (top1 == N-1) {
		printf("Queue is Full...\n");
	}
	else {
	        s1[++top1] = n;
	}
}

int pop1() {
	return s1[top1--];
}
void push2(int n) {
	if (top2 == N-1) {
                printf("Queue is Full...\n");
        }
        else {
                s2[++top2] = n;
        }
}
int pop2() {
        return s2[top2--];
}

void enqueue() {
	int x;
	printf("Enter the Data : ");
	scanf("%d", &x);
	if (top1 == N-1) {
                printf("Queue is Full...\n");
        }
        else {
	        push1(x);
                count++;
        }
}

void dequeue() {
	int a;
	if (top1 == -1 && top2 == -1) {
		printf("Queue is empty\n");
	}
	else {
		for(int i = 0; i < count; i++) {
		a = pop1();
		push2(a);
		}

		printf("Front element in Queue : %d\n",pop2());
		count--;

		for(int i = 0; i < count; i++) {
                a = pop2();
                push1(a);
		}
	}
}
 

void peek() {
	int a;
	if (top1 == -1) {
                printf("Queue is empty\n");
        }
	else {
		for(int i = 0; i < count; i++) {
                a = pop1();
                push2(a);
                }

		printf("Front Element in Queue : %d\n",s2[top2]);

                for(int i = 0; i < count; i++) {
                a = pop2();
                push1(a);
                }
	}
}

void display() {
	if (top1 == -1) {
                printf("Queue is empty\n");
        }
	else {
		for (int i = 0; i < count; i++) {
			printf("%d -> ",s1[i]);
		}
		printf("NULL\n");
	}
}

int main () {
     int ch;
     do {
	printf("============= Queue Operations by LinkedList ============ \n"
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
