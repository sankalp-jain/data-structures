#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class BinaryTreeNode{
public:
	T data;
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;

	BinaryTreeNode<T>(T data){
		this -> data = data;
		left = NULL;
		right = NULL;
	}
};

vector<int>* leafPath(BinaryTreeNode<int>* root, int data){
	if(root == NULL)
		return NULL;

	if(root -> data == data){
		vector<int>* v = new vector<int>();
		v->push_back(root -> data);
		return v;
	}
	vector<int>* leftPart = leafPath(root -> left, data);
	vector<int>* rightPart = leafPath(root -> right, data);

	if(leftPart != NULL){
		leftPart->push_back(root -> data);
		return leftPart;
	}
	else if(rightPart != NULL){
		rightPart->push_back(root -> data);
		return rightPart;
	}
	else
		return NULL;
}


int main(){
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
	BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
	BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
	BinaryTreeNode<int>* node3 = new BinaryTreeNode<int>(4);
	BinaryTreeNode<int>* node4 = new BinaryTreeNode<int>(5);
	BinaryTreeNode<int>* node5 = new BinaryTreeNode<int>(6);
	BinaryTreeNode<int>* node6 = new BinaryTreeNode<int>(7);

	root -> left = node1;
	root -> right = node2;

	node1 -> left = node3;
	node1 -> right = node4;
	
	node2 -> left = node5;
	node2 -> right = node6;

	vector<int>* vec = leafPath(root, 5);
	for (int i = 0; i < vec->size(); i++)
		cout << vec->at(i) << endl;
	return 0;
}
