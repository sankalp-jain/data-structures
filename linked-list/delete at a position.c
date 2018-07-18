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

void deleteAtPos(struct Node** head_ref, int pos){
	struct Node* temp = *head_ref, *prev;
	int c = 0;
	if (pos == 1){
		*head_ref = temp -> next;
		free(temp);
		return;
	}

	while(c != pos - 1 && temp -> next != NULL){
		prev = temp;
		temp = temp -> next;
		c++;
	}
	
	prev -> next = temp -> next;
	free(temp);
	return;
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

	deleteAtPos(&head, 1);
	
	printList(head);
}
