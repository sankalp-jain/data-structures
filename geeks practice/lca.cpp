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

vector<int>* lca(BinaryTreeNode<int>* root, int data){
	if(root == NULL)
		return NULL;
	if(root -> data == data){
		vector<int>* vec = new vector<int>();
		vec->push_back(root -> data);
		return vec;
	}

	vector<int>* leftOutput = lca(root -> left, data);
	if(leftOutput != NULL){
		leftOutput->push_back(root -> data);
		return leftOutput;
	}

	vector<int>* rightOutput = lca(root -> right, data);
	if(rightOutput != NULL){
		rightOutput->push_back(root -> data);
		return rightOutput;
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

	vector<int>* v = lca(root, 7);
	if(v == NULL)
	return 0;
	for (int i = 0; i < v->size(); i++)
		cout << v->at(i) << endl;
}
