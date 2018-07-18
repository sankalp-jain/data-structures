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

int searchRecursive(struct Node* head, int data){
	if (head == NULL)
		return 0;

	if (head -> data == data)
		return 1;

	return(searchRecursive(head -> next, data));

}

int main(){
	struct Node* head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	
	push(&head, 15);

	printList(head);

	bool search = searchRecursive(head, 1);
	printf("%s\n", "false\0true"+6*search);
}
