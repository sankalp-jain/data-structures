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
	int res = 0;
	while(fast_ptr != NULL && fast_ptr -> next != NULL){
		slow_ptr = slow_ptr -> next;
		fast_ptr = fast_ptr -> next -> next;
		if (slow_ptr == fast_ptr)
			break;
	}
	struct Node* temp = slow_ptr -> next;
	struct Node* temp1 = slow_ptr -> next -> next;
	while(temp != temp1){
		res++;
		temp1 = temp1 -> next;
	}
	printf("%d ", res + 1);
}

struct Node *newNode(int key)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    temp->next = NULL;
    return temp;
}

int main(){
	struct Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next;


	detectLoop(head);
}
