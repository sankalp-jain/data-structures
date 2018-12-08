#include <iostream>
#include <stack>
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
	while (temp != NULL){
		cout << temp -> data << endl;
		temp = temp -> next;
	}
}

node* takeInput(){
	int data;
	node* head = NULL, *tail = NULL;
	cin >> data;
	while (data != -1){
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
	stack <int> st;
	while(head != NULL){
		st.push(head -> data);
		head = head -> next;
	}
	int s = 0;

	for (int i = 0; i < n; i++){
		s += st.top();
		st.pop();
	}
	cout << s;
}
