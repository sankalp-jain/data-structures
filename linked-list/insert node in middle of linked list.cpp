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

node* middleNode(node* head){
	node* fastPtr = head, *slowPtr = head;
	while(fastPtr != NULL && fastPtr -> next != NULL){
		slowPtr = slowPtr -> next;
		fastPtr = fastPtr -> next -> next;
	}
	return slowPtr;
}

void print(node* head){
	node* temp = head;
	while(temp != NULL){
		cout <<temp -> data << " ";
		temp = temp -> next;
	}
	cout<<endl;
}

void insertMidNode(node* middNode){
	cout << "Enter new node data"<<endl;
	int newNodeData;
	cin >> newNodeData;
	node* newNode = new node(newNodeData);
	node* next = middNode -> next;
	middNode -> next = newNode;
	newNode -> next = next;
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
	insertMidNode(midNode);
	print(head);
}
