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
		cout << temp -> data << endl;
		temp = temp -> next;
	}
}

void length(node* head){
	node* fastPtr = head;
	while(fastPtr != NULL && fastPtr -> next != NULL){
		fastPtr = fastPtr -> next -> next;
	}
	if (fastPtr == NULL){
		cout << "Even";
	}
	else
		cout << "Odd";
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
	length(head);
}
