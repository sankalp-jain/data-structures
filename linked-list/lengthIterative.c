#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void push(struct Node** head_ref, int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = data;
	newNode -> next = *head_ref;
	*head_ref = newNode;
}

void lengthIterative(struct Node* head){
	int c = 0;
	while(head != NULL){
		c++;
		head = head -> next;
	}
	printf("c: %d ", c);
}

void printList(struct Node* head){
	while(head != NULL){
		printf("%d ", head -> data);
		head = head -> next;
	}
	printf("\n");
}

int main(){
	struct Node* head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);

	printList(head);

	lengthIterative(head);
}
