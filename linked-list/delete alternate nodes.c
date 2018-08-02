#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void push(struct Node** head, int data){
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node -> data = data;
	node -> next = *head;
	*head = node;
}

void printList(struct Node* node){
	while(node != NULL){
		printf("%d ", node -> data);
		node = node -> next;
	}
	printf("\n");
}

void delete(struct Node** head_ref){
	struct Node* temp, *next;
	struct Node* current = *head_ref;
	while(current != NULL && current -> next != NULL){
		temp = current -> next;
		current -> next = temp -> next;
		next = temp -> next;
		current = next;
		free(temp);
		// // if (current -> next -> next == NULL){
		// // 	current -> next = NULL;
		// // 	break;
		// }
	} 
}

int main(){
	struct Node* head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
		
	printList(head);

	delete(&head);

	printList(head);
}
