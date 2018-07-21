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

int pairwiseSwapRecursive(struct Node* node){

	if (node != NULL && node -> next != NULL){
	int a = node -> data;
	int b = node -> next -> data;
	node -> data = b;
	node -> next -> data = a;
	return (pairwiseSwapRecursive(node -> next -> next));
	}
}

int main(){
	struct Node* head = NULL;
	
	push(&head, 5);
    push(&head, 4);

	printList(head);

	pairwiseSwapRecursive(head);

	printList(head);
}
