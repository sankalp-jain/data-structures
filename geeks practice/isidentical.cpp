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

bool isIdentical(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2){
	if(root1 == NULL && root2 == NULL)
		return true;
	else if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
		return false;

	return root1 -> data == root2 -> data && isIdentical(root1 -> left, root2 -> left) && isIdentical(root1 -> right, root2 -> right);
}

int main(){
	BinaryTreeNode<int>* root1 = new BinaryTreeNode<int>(1);
	BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
	BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
	BinaryTreeNode<int>* node3 = new BinaryTreeNode<int>(4);
	BinaryTreeNode<int>* node4 = new BinaryTreeNode<int>(5);
	BinaryTreeNode<int>* node5 = new BinaryTreeNode<int>(6);

	root1 -> left = node1;
	root1 -> right = node2;

	node1 -> left = node3;
	node1 -> right = node4;
	
	node2 -> left = node5;

		
	BinaryTreeNode<int>* root2 = new BinaryTreeNode<int>(1);
	BinaryTreeNode<int>* node1a = new BinaryTreeNode<int>(2);
	BinaryTreeNode<int>* node2a = new BinaryTreeNode<int>(3);
	BinaryTreeNode<int>* node3a = new BinaryTreeNode<int>(4);
	BinaryTreeNode<int>* node4a = new BinaryTreeNode<int>(5);
	BinaryTreeNode<int>* node5a = new BinaryTreeNode<int>(6);
	BinaryTreeNode<int>* node6a = new BinaryTreeNode<int>(7);

	root2 -> left = node1a;
	root2 -> right = node2a;

	node1a -> left = node3a;
	node1a -> right = node4a;
	
	node2a -> left = node5a;
	node2a -> right = node6a;


	cout << isIdentical(root1, root2);
	return 0;
}
