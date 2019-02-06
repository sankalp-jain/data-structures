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

bool pairRoothelper(BinaryTreeNode<int>* root, int x){
	if(root == NULL)
		return 0;
	
	if(root -> left != NULL && root -> right != NULL)
		if(root -> left -> data + root -> right -> data == x)
			return true;
	
	bool value1 = pairRoothelper(root -> left, x);
	bool value2 = pairRoothelper(root -> right, x);
	return value1 || value2;
}

bool pairRoot(BinaryTreeNode<int>* root){
	int x = root -> data;
	bool res = pairRoothelper(root, x);
	return res;
}


//9 8 6 5 2 1 -1 -1 -1 -1 -1 -1 -1
int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	printTree(root);
	cout << pairRoot(root) << endl;
}
