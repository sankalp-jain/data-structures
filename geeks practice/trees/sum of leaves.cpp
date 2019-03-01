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

int sumLeaves(BinaryTreeNode<int>* root){
	if(root == NULL)
		return 0;

	static int s = 0;
	if(root -> left == NULL && root -> right == NULL){
		s += root -> data;
		cout << root -> data << endl;	
	}

	int s1 = sumLeaves(root -> left);
	int s2 = sumLeaves(root -> right);

	return s;
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

	int sum = sumLeaves(root);
	cout << sum << endl;
	return 0;
}
