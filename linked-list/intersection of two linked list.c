#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void push(struct Node** head, int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = data;
	newNode -> next = *head;
	*head = newNode; 
}

void printList(struct Node* node){
	while(node != NULL){
		printf("%d ", node -> data);
		node = node -> next;
	}
	printf("\n");
}

struct Node* sortedInterstect(struct Node* a, struct Node* b){
	struct Node dummy;
	struct Node* tail = &dummy;
	dummy.next = NULL;

	while(a != NULL && b != NULL){
		if (a -> data == b -> data){
			push((&tail -> next), a -> data);
			tail = tail -> next;
			a = a -> next;
			b = b -> next;
		}
		else if (a ->  data < b -> data)
			a = a -> next;
		else
			b = b -> next;
	}
	return dummy.next;
}

int main(){
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;

	push(&head1, 6);
	push(&head1, 4);
	push(&head1, 3);
	push(&head1, 2);
	push(&head1, 1);

	push(&head2, 8);
	push(&head2, 6);
	push(&head2, 4);
	push(&head2, 2);

	printList(head1);
	printList(head2);

	struct Node* intersect = sortedInterstect(head1, head2);
	printList(intersect);
}