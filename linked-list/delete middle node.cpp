#include <iostream>
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

void print(node* head){
	node* temp = head;
	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

node* middleNode(node* head){
	node* fastPtr = head, *slowPtr = head;
	while(fastPtr != NULL && fastPtr -> next != NULL){
		slowPtr = slowPtr -> next;
		fastPtr = fastPtr -> next -> next;
	}
	return slowPtr;
}

void deleteNode(node* head, node* midNode){
	node* temp = head;
	node* next = NULL;
	while(temp -> next != NULL){
		if (temp -> next == midNode){
			next = temp -> next;
			temp -> next = next -> next;
		}
		temp = temp -> next;
	}
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

int main(){
	node* head = takeInput();
	print(head);
	node* midNode = middleNode(head);
	deleteNode(head, midNode);
	print(head);
}
