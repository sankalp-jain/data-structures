#include <iostream>
#include<stdlib.h>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int data){
		this -> data = data;
		this -> next = NULL;
	}
};

node* middleNode(node* head){
	node* fastPtr = head;
	node* slowPtr = head;

	while(fastPtr != NULL && fastPtr -> next != NULL){
		fastPtr = fastPtr -> next -> next;
		slowPtr = slowPtr -> next;
	}
	return slowPtr;
}


void freeMidNode(node* head, node* midNode){
	node* temp = head;
	node* prev = NULL;
	node* next = NULL;
	while(temp != NULL){
		prev = temp;
		next = temp -> next;
		if (temp -> next == midNode){
			prev -> next = next -> next;
			next -> next = NULL;
			break;
		}
		temp = temp -> next;
	}
}

void makeMiddleNodeHead(node* head, node* midNode){
	midNode -> next = head;
}

node* takeInput(){
	int data;
	cin >> data;
	node* head = NULL, *tail = NULL;

	while(data != -1){
		node* newNode = new node(data);
		if (head == NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			tail -> next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(node* head){
	node* temp = head;
	while(temp != NULL){
		cout << temp -> data <<endl;
		temp = temp -> next;
	}
}

int main(){
	node* head = takeInput();
	node* midNode = middleNode(head);
	freeMidNode(head, midNode);
	makeMiddleNodeHead(head, midNode);
	print(midNode);
}
