#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void push(struct Node** head, int data){
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node -> data = data;
	node -> next = *head;
	*head = node;
}

void printList(struct Node* head){
	while(head != NULL){
		printf("%d ", head -> data);
		head = head -> next;
	}
	printf("\n");
}

void insert(struct Node* head, int pos, int key){
	int c = 0;
	struct Node* prev = head;
	struct Node* next = NULL;
	while(c != pos - 1){
		prev = prev -> next;
		printf("%d ", head->data);
		next = prev -> next;
		c++;
		printf("c: %d\n", c);
	}
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = key;
	prev -> next = newNode;
	newNode -> next = next;
}

void insertEnd(struct Node* head, int data){
	struct Node* node = head;
	while(node -> next != NULL){
		node = node -> next;
	}
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = data;
	newNode -> next = NULL;
	node -> next = newNode;

}

int main(){
	struct Node* head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);

	printList(head);

	//insertion at beginning is same as pushing function

	//insertion at 4 position from the start

	insert(head, 4, 12);
	printList(head);

	//insertion at end

	insertEnd(head, 15);
	printList(head);
}
