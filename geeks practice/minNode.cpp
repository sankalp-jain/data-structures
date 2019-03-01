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

BinaryTreeNode<int>* minNode(BinaryTreeNode<int>* root){
	if(root == NULL)
		return NULL;

	if(root -> left){
		BinaryTreeNode<int>* leftPart = minNode(root -> left);
		return leftPart;
	}
	else
		return root;
}


int main(){
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(20);
	BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(8);
	BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(22);
	BinaryTreeNode<int>* node3 = new BinaryTreeNode<int>(4);
	BinaryTreeNode<int>* node4 = new BinaryTreeNode<int>(12);
	BinaryTreeNode<int>* node5 = new BinaryTreeNode<int>(10);
	BinaryTreeNode<int>* node6 = new BinaryTreeNode<int>(14);

	root -> left = node1;
	root -> right = node2;

	node1 -> left = node3;
	node1 -> right = node4;
	
	node4 -> left = node5;
	node4 -> right = node6;

	cout << minNode(root) -> data;
}
