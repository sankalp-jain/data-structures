#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void push(struct Node** head_ref, int data){
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node -> data = data;
	node -> next = *head_ref;
	*head_ref = node;
}

void deleteAKey(struct Node** head_ref, int data){
	struct Node* temp = *head_ref, *prev;
	if (temp -> data == data){
		*head_ref = temp -> next;
		free(temp);
		return;
	}

	while(temp -> data != data && temp -> next != NULL){
		prev = temp;
		temp = temp -> next;
	}
	
	if (temp -> data == data){
		prev -> next = temp -> next;
		free(temp);
		return;
	}	
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

	printList(head);

	deleteAKey(&head, 2);
	
	printList(head);
}
