#include <iostream>
#include<map>
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
	cin >> data;
	node* head = NULL, *tail = NULL;

	while(data != -1){
		node *newNode = new node(data);
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
	cout << "First LL" <<endl;
	node* head1 = takeInput();
	//print(head1);
	
	cout << "Second LL" << endl;
	node* head2 = takeInput();
	//print(head2);

	map<int, int> unionMap;
	map<int, int> intersectionMap;
	node* temp1 = head1;
	while(temp1 != NULL){
		unionMap[temp1 -> data] = 1;
		intersectionMap[temp1 -> data] = 1;
		temp1 = temp1 -> next;
	}

	node* temp2 = head2;
	while (temp2 != NULL){
		if (unionMap.count(temp2 -> data) == 0){
			unionMap[temp2 -> data] = 1;
		}
		if (intersectionMap.count(temp2 -> data) > 0){
			intersectionMap[temp2 -> data]++;
		}
		temp2 = temp2 -> next;
	}

	map<int, int> :: iterator it = unionMap.begin();
	while(it != unionMap.end()){
		cout << it -> first <<endl;
		++it;
	}
	
	cout << endl << endl << endl; 

	map<int, int> :: iterator it1 = intersectionMap.begin();
	while(it1 != intersectionMap.end()){
		if (it1 -> second > 1)
			cout << it1 -> first <<endl;
		++it1;
	}
}
