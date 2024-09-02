#include <stdio.h> 
#include <stdlib.h>

typedef struct Circular_LinkedList {
	int data;
	struct Circular_LinkedList* next;
} Node;

Node* head = NULL;
Node* tail = NULL;


int get_count () {
	int count = 0;
	Node* temp = head;
	if (temp) {
		count++;
		while (temp->next != head) {
			temp = temp->next;
			count++;
		}
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
	        head = tail = new;
		tail->next = head;
	}
	else {
		new->next = head;
		head = new;
		tail->next = head;
	}
}

void Insert_end () {
	Node* new = CreateNode();
        if (new == NULL) {
                printf("Memory allocation failed\n");
                return ;
        }

	if (head == NULL) {
               head = tail = new;
	       tail->next = head;
	}
        else {
		tail->next = new;
		tail = new;
		tail->next = head;
	}
}

void Insert_position() {
	int pos, i = 1;
	int cnt = get_count();

	printf("Enter the Position: ");
	scanf("%d", &pos);
	
	if(pos > cnt) {
		printf("Invalid Position\n");
                return ;
        }
	
	Node* new = CreateNode();
        if (new == NULL) {
                printf("Memory allocation failed\n");
                return ;
        }

	if (pos == i) {
		new->next = head;
                head = new;
                tail->next = head;
	}
	else {
		Node* temp = head;
		while (i < pos-1) {
			temp = temp->next;
			i++;
		}
		new->next = temp->next;
		temp->next = new;
	}
}

void Del_front() {
	int cnt = get_count();
	Node* temp = head;

        if(cnt >= 1 && temp != NULL) {
		head = tail->next->next;
		tail->next = head;
		free(temp);
	}
	else {
                printf("Empty LinkedList..\n");
                return ;
        }
}

void Del_end() {
	int cnt = get_count();
        Node* temp = head;
	Node* prev = NULL;

        if(cnt >= 1 && temp != NULL) {
		while (temp->next != head ) {
			prev = temp;
			temp = temp->next;
		}
		tail = prev;
		tail->next = head;
		free(temp);
	}
	else {
		printf("Empty LinkedList..\n");
                return ;
        }
}

void Del_position() {
	int pos, i = 1;
        int cnt = get_count();

        printf("Enter the Position: ");
        scanf("%d", &pos);

        if(pos > cnt) {
                printf("Invalid Position\n");
                return ;
        }
	Node* temp = head;

        if (pos == i) {
		head = tail->next->next;
                tail->next = head;
                free(temp);
        }
	else if (pos == cnt) {
                while (i < pos-1) {
                        temp = temp->next;
                        i++;
                }
		Node* temp2 = temp->next;
		tail = temp;
		tail->next = head;
		free(temp2);
        }
	else {
		while (i < pos-1) {
                        temp = temp->next;
                        i++;
                }
		Node* temp2 = temp->next;
		temp->next = temp2->next;
		free(temp2);
	}
}

void reverse() {
}

void display () {
	Node* temp = head;
	if(temp) {
		while(temp->next != head) {
			printf("%d -> ", temp->data);
			temp = temp->next;
		}
		printf("%d -> NULL\n",temp->data);
	}
	else {
		printf("Empty LinkedList..\n");
                return ;
        }
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











