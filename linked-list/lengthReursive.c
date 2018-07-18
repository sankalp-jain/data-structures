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

int lengthRecursive(struct Node* head){
	int c = 0;
	if (head == NULL)
		return c;
	else
		return 1 + lengthRecursive(head -> next);
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

	printList(head);

	int l = lengthRecursive(head);
	printf("l: %d ", l);
}
