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

void sumTree(BinaryTreeNode<int>* root, int &sum){
	if(root == NULL)
		return;

	sum += root -> data;
	sumTree(root -> left, sum);
	sumTree(root -> right, sum);
}

bool subTreeSum(BinaryTreeNode<int>* root, int *curr_sum ,int data){
	if(root == NULL){
		*curr_sum = 0;
		return false;
	}

	int leftSum = 0, rightSum = 0;
	sumTree(root -> left, leftSum);
	sumTree(root -> right, rightSum);

	return ((*curr_sum = root -> data + leftSum + rightSum) == data); 

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
	
	int curr_sum = 0;
	cout << subTreeSum(root, &curr_sum, 11);
	return 0;
}
