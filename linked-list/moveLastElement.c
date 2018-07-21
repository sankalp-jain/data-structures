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

/*Alternate function for same functionality*/

//void moveLastElement(struct Node** head){
//	struct Node* node = *head;
//	struct Node* prev;
//	while(node -> next != NULL){
//		prev = node;
//		node = node -> next;
//	}
//	node -> next = *head;
//	*head = node;
//	prev -> next = NULL;
//}

struct Node* moveLastElement(struct Node* head){
	struct Node* node = head;
	struct Node* prev;
	if (head == NULL)
		return;
	while(node -> next != NULL){
		prev = node;
		node = node -> next;
	}
	node -> next = head;
	head = node;
	prev -> next = NULL;
	return head;
}

int main(){
	struct Node* head = NULL;
	
	push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);

	printList(head);

	struct Node* node1 = moveLastElement(head);

	printList(node1);
}
