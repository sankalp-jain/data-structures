#include<iostream>
#include<queue>
using namespace std;
template <typename T>

class BinaryTreeNode{
public:
	T data;
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;

	BinaryTreeNode(T data){
		this -> data = data;
		this -> left = NULL;
		this -> right = NULL;
	}
};

BinaryTreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter left child of " << front->data << endl;
		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}
		cout << "Enter right child of " << front->data << endl;
		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}

void printTree(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << ":";
	if (root->left != NULL) {
		cout << "L" << root->left->data;
	}

	if (root->right != NULL) {
		cout << "R" << root->right->data;
	}
	cout << endl;
	printTree(root->left);
	printTree(root->right);
}

bool checkChildren(BinaryTreeNode<int>* root){
	if(root == NULL || (root -> left == NULL && root -> right == NULL))
		return true;
	
	int s = 0;
	if(root -> left != NULL)
		s += root -> left -> data;
	
	if(root -> right != NULL)
		s += root -> right -> data;

	if(root -> data == s){
		bool value1 = checkChildren(root -> left);
		bool value2 = checkChildren(root -> right);
		return value1 && value2;
	}
	else
		return false;
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	printTree(root);
	cout << checkChildren(root) << endl;
}
