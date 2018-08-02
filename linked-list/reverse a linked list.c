#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

void push(struct Node** head_ref, int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = data;
	newNode -> next = *head_ref;
	*head_ref = newNode;
}

void printList(struct Node* node){
	while(node != NULL){
		printf("%d ", node -> data);
		node = node -> next;
	}
	printf("\n");
}

void reverse(struct Node** head){
	struct Node* current = *head;
	struct Node* prev = NULL, *next = NULL;


	while(current != NULL){
		next = current -> next;
		current -> next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

int main(){
	struct Node* head = NULL;
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	printList(head);

	reverse(&head);

	printList(head);
}
