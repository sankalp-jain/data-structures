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

void detectLoop(struct Node* head){
	struct Node* fast_ptr = head;
	struct Node* slow_ptr = head;
	
	while(fast_ptr != NULL && fast_ptr -> next != NULL){
		slow_ptr = slow_ptr -> next;
		fast_ptr = fast_ptr -> next -> next;
		if (slow_ptr == fast_ptr){
			printf("True\n");
			return;
		}
	}
	printf("False\n");
}

int main(){
	struct Node* head = NULL;
	push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    /* Create a loop for testing */
    head->next->next->next->next = head;


	detectLoop(head);
}
