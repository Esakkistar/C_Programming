#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Linked_List {
	int data;
	struct Linked_List* next;
} Node;

Node* head = NULL;

int get_count () {
	int count = 0;
	Node* temp = head;
	while (temp) {
		temp = temp->next;
		count++;
	}
	return count;
}


Node* CreateNode () {
	Node* new = (Node*) malloc (sizeof(Node));
	if (new == NULL) {
		printf("Memory allocation failed\n");
		exit(1);
	}
	printf("Enter the data : ");
	scanf("%d", &new->data);
	new->next = NULL;

	return new;
}

void Insert_front() {
	Node* new = CreateNode();
	if (new == NULL) {
                printf("Memory allocation failed\n");
                return ;
        }

	if (head == NULL) {
	        head = new;
	}
	else {
		new->next = head;
		head = new;
	}
}

void Insert_end () {
	Node* new = CreateNode();
        if (new == NULL) {
                printf("Memory allocation failed\n");
                return ;
        }

	Node* temp = head;

	if (head == NULL)
               head = new;
        else {
	       while (temp->next) {
		      temp = temp->next;
	       }
	       temp->next = new;
	}
}

void Insert_position () {
	int pos, count, n = 1;

	printf("Enter the position you want to add data : ");
	scanf("%d",&pos);
	count = get_count();

	if (pos > count) {
		printf("Invalid Position..\n");
		return ;
	}
        
	Node* new = CreateNode();
        if (new == NULL) {
                printf("Memory allocation failed\n");
                return ;
        }
	
	Node* temp = head;
	
	if (pos == 1) {
		new->next = head;
		head = new;
	}
	else {
		while (n < pos -1 ) {
			temp = temp->next;
			n++;
		}
		new->next = temp->next;
		temp->next = new;
	}
}

void Del_front () {
	Node* temp = head;
	if (temp != NULL) {
		head = temp->next;
		free(temp);
	}
}

void Del_end () {
	Node* temp = head;
	Node* prev = NULL;

	if (temp != NULL) {
		while (temp->next) {
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		free(temp);
	}
}

void Del_position () {
	int pos, count, n = 1;

        printf("Enter the position you want to delete : ");
        scanf("%d",&pos);
        count = get_count();

        if (pos > count) {
                printf("Invalid Position..\n");
                return ;
        }

	Node* temp = head;
	Node* prev = NULL;

	if (temp != NULL) {
		while (n < pos -1) {
			prev = temp;
			temp = temp->next;
			n++;
		}
		prev = temp->next;
		temp->next = prev->next;
		free(prev);
	}
}

void display () {
	Node* temp = head;
        printf("Display : ");
	while (temp) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL \n");
}

void reverse() {
	Node* current = head;
	Node* prev = NULL;
	Node* next = NULL;
        
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	head = prev;
        printf("Reverse LinkedList ");
	display();
}

int main () {
        int N;
        while(1) {
	     printf("1. Insertion at front \n"
	            "2. Insertion at End \n"
		    "3. Insertion at AnyPosition \n"
		    "4. Deletion at Front \n"
		    "5. Deletion at End \n"
		    "6. Deletion at AnyPosition \n"
		    "7. Display \n"
		    "8. Reverse Linked List \n"
		    "9. Exit\n");

	     printf ("Choose Option : ");
	     scanf("%d", &N);

              switch (N) {
                   case 1:
                        Insert_front();
                        printf("Insertion at Front completed.\n");
                        break;
                   case 2:
                        Insert_end();
                        printf("Insertion at End completed.\n");
                        break;
		   case 3:
                        Insert_position();
                        printf("Insertion at AnyPosition completed.\n");
                        break;
                   case 4:
                        Del_front();
                        printf("Deletion at Front Completed.\n");
                        break;
                   case 5:
                        Del_end();
                        printf("Deletion at End selected.\n");
                        break;
                   case 6:
                        Del_position();
                        printf("Deletion at AnyPosition selected.\n");
                        break;
                   case 7:
                        printf("Display selected.\n");
                        display();
                        break;
		   case 8:
			reverse();
			break;
                   case 9:
                        printf("Exiting...\n");
                        return 0;
                   default:
                        printf("Please choose a correct option.\n");
                        break;
              }
        }

        return 0;
}
