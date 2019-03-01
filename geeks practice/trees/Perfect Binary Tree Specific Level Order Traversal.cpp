#include <iostream>
#include <queue>
#include<vector>
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

void bfs(BinaryTreeNode<int>* root){
	if(root == NULL)
		return;

	queue<BinaryTreeNode<int>*> q;
	vector<BinaryTreeNode<int*>> vec;
	q.push(root);
	q.push(NULL);
	while(q.size() > 1){
		BinaryTreeNode<int>* front = q.front();
		vector<BinaryTreeNode<int*>> vec;
		q.pop();
		if(front == NULL){
			q.push(NULL);
			if(vec.size() != 1){
				
			}
			cout << endl;
		}
		else{
			cout << front -> data << " ";
			if(front -> left != NULL)
				q.push(front -> left);
			if(front -> right != NULL)
				q.push(front -> right);
		}
	}
}

int main(){
	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1); 
  
    root->left        = new BinaryTreeNode<int>(2); 
    root->right       = new BinaryTreeNode<int>(3); 
  
    root->left->left  = new BinaryTreeNode<int>(4); 
    root->left->right = new BinaryTreeNode<int>(5); 
    root->right->left  = new BinaryTreeNode<int>(6); 
    root->right->right = new BinaryTreeNode<int>(7); 
  
    root->left->left->left  = new BinaryTreeNode<int>(8); 
    root->left->left->right  = new BinaryTreeNode<int>(9); 
    root->left->right->left  = new BinaryTreeNode<int>(10); 
    root->left->right->right  = new BinaryTreeNode<int>(11); 
    root->right->left->left  = new BinaryTreeNode<int>(12); 
    root->right->left->right  = new BinaryTreeNode<int>(13); 
    root->right->right->left  = new BinaryTreeNode<int>(14); 
    root->right->right->right  = new BinaryTreeNode<int>(15); 
  
    root->left->left->left->left  = new BinaryTreeNode<int>(16); 
    root->left->left->left->right  = new BinaryTreeNode<int>(17); 
    root->left->left->right->left  = new BinaryTreeNode<int>(18); 
    root->left->left->right->right  = new BinaryTreeNode<int>(19); 
    root->left->right->left->left  = new BinaryTreeNode<int>(20); 
    root->left->right->left->right  = new BinaryTreeNode<int>(21); 
    root->left->right->right->left  = new BinaryTreeNode<int>(22); 
    root->left->right->right->right  = new BinaryTreeNode<int>(23); 
    root->right->left->left->left  = new BinaryTreeNode<int>(24); 
    root->right->left->left->right  = new BinaryTreeNode<int>(25); 
    root->right->left->right->left  = new BinaryTreeNode<int>(26); 
    root->right->left->right->right  = new BinaryTreeNode<int>(27); 
    root->right->right->left->left  = new BinaryTreeNode<int>(28); 
    root->right->right->left->right  = new BinaryTreeNode<int>(29); 
    root->right->right->right->left  = new BinaryTreeNode<int>(30); 
    root->right->right->right->right  = new BinaryTreeNode<int>(31); 

	bfs(root);
}
