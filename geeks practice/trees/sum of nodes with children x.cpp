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


int sumOfNodesX(BinaryTreeNode<int>* root, int x){
	if(root == NULL)
		return 0;
	
	int s = 0;

	if((root -> left != NULL && root -> left -> data == x) || (root -> right != NULL && root -> right -> data ==x))
		s += root -> data;	
	s += sumOfNodesX(root -> left, x);
	s += sumOfNodesX(root -> right, x);
	cout << s << endl;
	return s;
}

//4 2 5 7 2 2 3 -1 -1 -1 -1 -1 -1 -1 -1
int main(){
	cout << "cdnjdc" << endl;
	BinaryTreeNode<int>* root = takeInputLevelWise();
	int x;
	cout <<"Enter X" << endl;
	cin >> x;
	int sum = sumOfNodesX(root, x);
	cout <<"Sum: " << sum << endl;
}
