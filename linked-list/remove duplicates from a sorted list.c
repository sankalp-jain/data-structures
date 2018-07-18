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

void removeDuplicates(struct Node* head){
	struct Node* current = head;
	struct Node* next_next;

	if (current == NULL)
		return;

	while(current -> next != NULL){
		if (current -> data == current -> next -> data){
			next_next = current -> next -> next;
			free(current -> next);
			current -> next = next_next;
		}
		else{
			current = current -> next;
		}
	}
}

int main(){
	struct Node* head = NULL;
	push(&head, 20);
    push(&head, 13);
    push(&head, 13);  
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);                                    

    printList(head);

    removeDuplicates(head);

    printList(head);
}
