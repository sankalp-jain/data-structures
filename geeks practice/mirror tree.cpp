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

void levelOrderTraversal(BinaryTreeNode<int>* root){
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	q.push(NULL);

	while(q.size() > 1){
		BinaryTreeNode<int>* front = q.front();
		q.pop();
		if(front == NULL){
			cout << endl;
			q.push(NULL);	
		}
		else{
			cout << front -> data << " ";
			if(front -> left){
				q.push(front -> left);
			}
			if(front -> right){
				q.push(front -> right);
			}
			cout << " ";
		}
	}
}

BinaryTreeNode<int>* mirror(BinaryTreeNode<int>* root1){
	if(root1 == NULL)
		return NULL;

	BinaryTreeNode<int>* root2 = new BinaryTreeNode<int>(root1 -> data);
	BinaryTreeNode<int>* leftRoot = mirror(root1 -> left);
	BinaryTreeNode<int>* rightroot = mirror(root1 -> right);
	root2 -> left = leftRoot;
	root2 -> right = rightroot;
	return root2;

}


int main(){
	BinaryTreeNode<int>* root1 = new BinaryTreeNode<int>(1);
	BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
	BinaryTreeNode<int>* node6 = new BinaryTreeNode<int>(7);

	root1 -> left = node1;

	node1 -> left = node6;


	BinaryTreeNode<int>* root2 = mirror(root1);
	levelOrderTraversal(root2);
	return 0;
}
