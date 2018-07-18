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

void printMiddle(struct Node* head){
	struct Node* fast_ptr = head;
	struct Node* slow_ptr = head;
	
	while(fast_ptr != NULL && fast_ptr -> next != NULL){
		slow_ptr = slow_ptr -> next;
		fast_ptr = fast_ptr -> next -> next;
	}
	printf("%d\n", slow_ptr -> data);
}

int main(){
	struct Node* head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	push(&head, 6);
	printList(head);

	printMiddle(head);
}
