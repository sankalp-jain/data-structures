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

void inorder(BinaryTreeNode<int>* root){
	if(root == NULL)
		return;

	inorder(root -> left);
	cout << root -> data;
	inorder(root -> right);

}

void preorder(BinaryTreeNode<int>* root){
	if(root == NULL)
		return;
	cout << root -> data;
	preorder(root -> left);
	preorder(root -> right);

}

void postorder(BinaryTreeNode<int>* root){
	if(root == NULL)
		return;
		
	postorder(root -> left);
	postorder(root -> right);
	cout << root -> data;

}

void bfs(BinaryTreeNode<int>* root){
	if(root == NULL)
		return;

	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	while(!q.empty()){
		BinaryTreeNode<int>* front = q.front();
		q.pop();
		cout << front->data;
		if(front -> left != NULL)
			q.push(front -> left);
		if(front -> right != NULL)
			q.push(front -> right);
	}
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
	cout << endl;
	preorder(root);
	cout << endl;
	postorder(root);
	cout << endl;
	bfs(root);


}
