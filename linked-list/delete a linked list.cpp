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

void printList(struct Node* head){
	while(head != NULL){
		printf("%d ", head -> data);
		head = head -> next;
	}
	printf("\n");
}

void deleteList(struct Node** head_ref){
	struct Node* current = *head_ref, *next;
	while(current != NULL){
		next = current -> next;
		free(current);
		current = next;
	}
	*head_ref = NULL;
}

int main(){
	struct Node* head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);

	printList(head);

	deleteList(&head);

	printList(head);
}
