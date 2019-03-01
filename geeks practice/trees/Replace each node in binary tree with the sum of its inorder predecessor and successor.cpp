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

void replace(BinaryTreeNode<int>* root, vector<int> &vec){
	if(root == NULL)
		return;

	int data = root -> data;
	for (int i = 0; i < vec.size(); i++)
		if(vec[i] == data)
			root -> data = vec[i - 1] + vec[i + 1];

	replace(root -> left, vec);
	replace(root -> right, vec); 
}

void preorder(BinaryTreeNode<int>* root){
	if(root == NULL)
		return;

	cout << root -> data<<" ";
	preorder(root -> left);
	preorder(root -> right);
}

void inorder(BinaryTreeNode<int>* root, vector<int> &vec){
	if(root == NULL)
		return;

	inorder(root -> left, vec);
	vec.push_back(root -> data);
	inorder(root -> right, vec);
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

	vector<int> vec;
	vec.push_back(0);
	preorder(root);
	cout << endl;
	inorder(root, vec);
	vec.push_back(0);
	replace(root, vec);
	preorder(root);
	cout << endl;


}
