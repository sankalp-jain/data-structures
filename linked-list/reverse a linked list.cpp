#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(int data){
		this -> data = data;
		next = NULL;
	}
};

void push(Node* head, int data){
	Node* temp = new Node(data);
	Node* tempHead = head;
	while(tempHead -> next != NULL){
		tempHead = tempHead -> next;
	}
	tempHead -> next = temp;
	temp -> next = NULL;
}

void printLL(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}
}



Node* intersection(Node* newHead, Node* head1, Node* head2){
	while(head1 != NULL && head2 != NULL){
		if(head1 -> data == head2 -> data){
			push(newHead, head1 -> data);
			head1 = head1 -> next;
			head2 = head2 -> next;
		}
		else if(head1 -> data < head2 -> data){
			head1 = head1 -> next;	
		}
		else{
			head2 = head2 -> next;	
		}
	}
	return newHead;
}

int main(){
	Node* head1 = new Node(0);
	push(head1, 1); 
	push(head1, 2); 
	push(head1, 3); 
	push(head1, 4);
	push(head1, 5); 

	Node* head2 = new Node(-7);
	push(head2, 2); 
	push(head2, 3); 
	push(head2, 4);
	push(head2, 5); 
	
	Node* newHead = new Node(-1);
	Node* temp = intersection(newHead, head1, head2);
	printLL(temp);


}
