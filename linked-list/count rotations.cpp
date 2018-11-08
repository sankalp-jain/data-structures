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

int countRot(node* head){
	node* temp = head;
	int c = 0;
	while(temp != NULL){
		if (temp -> data > temp -> next -> data)
			return c + 1;
		else{
			c++;
			temp = temp -> next;
		}
	}
}

void print(node* head){
	node* temp = head;
	while(temp != NULL){
		cout << temp -> data <<endl;
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
	int c = countRot(head);
	cout<<c;
}
