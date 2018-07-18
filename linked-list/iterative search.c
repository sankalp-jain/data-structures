#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool searchIterative(struct Node* head, int data){
	int k = 0;
	while(head != NULL){
		if (head -> data == data){
			k = 1;
			return true;
		}
		head = head -> next;
	}
	if (k == 0)
		return false;
}

int main(){
	struct Node* head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	
	push(&head, 1);

	printList(head);

	bool search = searchIterative(head, 1);
	printf("%s\n", "false\0true" + 6*search);
}
