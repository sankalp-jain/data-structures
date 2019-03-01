#include <iostream>
#include <queue>
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

void inorderHelper(BinaryTreeNode<int>* root, int x){
	if(root == NULL)
		return;
	static int c = 0;
	
	inorderHelper(root -> left, x);
	c += 1;
	if(c == x)
		cout << root -> data;
	inorderHelper(root -> right, x);
}

void inorder(BinaryTreeNode<int>* root){
	inorderHelper(root, 5);
}

int main(){
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
	BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
	BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
	BinaryTreeNode<int>* node3 = new BinaryTreeNode<int>(4);
	BinaryTreeNode<int>* node4 = new BinaryTreeNode<int>(5);

	root -> left = node1;
	root -> right = node2;

	node1 -> left = node3;
	node1 -> right = node4;

	inorder(root);
}
