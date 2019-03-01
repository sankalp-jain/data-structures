#include <iostream>
#include <stack>
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


void inorder(BinaryTreeNode<int>* root){
	stack<BinaryTreeNode<int>*> st;

	BinaryTreeNode<int>* current = root;
	st.push(current);
	current = current -> left;

	while(current != NULL && !st.empty()){
		BinaryTreeNode<int>* top = st.top();
		cout << top -> data;
		st.pop();
		current = top -> right;
		st.push(current);
		current = current -> left;
	}
}

int main(){

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
	BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
	BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
	BinaryTreeNode<int>* node3 = new BinaryTreeNode<int>(4);
	BinaryTreeNode<int>* node4 = new BinaryTreeNode<int>(5);

	inorder(root);
}
