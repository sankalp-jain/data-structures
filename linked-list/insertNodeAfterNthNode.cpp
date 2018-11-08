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
	node* temp = NULL;
	while(temp != NULL){
		cout << temp -> data << endl;
		temp = temp -> next;
	}
}

void insertNodeAfterNthNode(node* head, int n){
	node* temp = head;
	int c = 0;
	node* fastPtr = head;
	node* slowPtr = head;
	node* insertNode = new node(12);
	while(temp != NULL){
		cout <<temp -> data<<endl;
		if (c <= n){
			c++;
			fastPtr = fastPtr -> next;
		}
		else{
			c++;
			slowPtr = slowPtr -> next;
			fastPtr = fastPtr -> next;
		}
		temp = temp -> next;
	}

	insertNode -> next = slowPtr -> next;
	slowPtr -> next = insertNode;
	cout << "jhjh" << slowPtr -> data <<endl;
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
	int n;
	cin >> n;
	insertNodeAfterNthNode(head, n);
	print(head);
}
