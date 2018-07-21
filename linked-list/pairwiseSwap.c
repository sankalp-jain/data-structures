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

void pairwiseSwap(struct Node* node){
	while(node != NULL && node -> next != NULL){
		int a = node -> data;
		int b = node -> next -> data;
		node -> data = b;
		node -> next -> data = a;
		node = node -> next -> next;
	}
}

int main(){
	struct Node* head = NULL;
	
	push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);	

	printList(head);

	pairwiseSwap(head);

	printList(head);
}
