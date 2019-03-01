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

void inorderVec(BinaryTreeNode<int>* root, int data, vector<int> &vec){
	if(root == NULL)
		return;

	inorderVec(root -> left, data, vec);
	vec.push_back(root -> data);
	
	if(root -> data == data)
		return;	
	inorderVec(root -> right, data, vec);
}

void inorder(BinaryTreeNode<int>* root, int data, int &pos){
	if(root == NULL)
		return;

	inorder(root -> left, data, pos);
	if(root -> data == data){
		pos = 1;
		return;
	}
	inorder(root -> right, data, pos);
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

	int data, pos = 0;
	vector<int> vec;
	cin >> data;
	if(root -> left)
		inorder(root -> left, data, pos);
	cout << pos << endl;
	vec.push_back(root -> data);
	if(pos == 1){
		inorderVec(root -> left, data, vec);
	}
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";


}
