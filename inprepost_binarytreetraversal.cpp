#include<iostream>
#include<vector>
#include<queue>

using namespace std;

template<typename T>
class binarytreenode {
public:
	T data;
	binarytreenode* left;
	binarytreenode* right;
	binarytreenode(T data) {
		this->data = data;
		left = NULL;
		right = NULL;

	}
	~binarytreenode() {
		delete left;
		delete right;
	}
};




void inorder(binarytreenode<int> *root) {
	if (root == NULL) {
		return;

	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}


void preorder(binarytreenode<int> *root) {
	if (root == NULL) {
		return;

	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}


void postorder(binarytreenode<int> *root) {
	if (root == NULL) {
		return;

	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}


int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("out.txt", "w", stdout);
#endif

	struct binarytreenode<int>* root = new binarytreenode<int>(1);
	root->left = new binarytreenode<int>(2);
	root->right = new binarytreenode<int>(3);
	root->left->left = new binarytreenode<int>(4);
	root->left->right = new binarytreenode<int>(5);

	cout << "\nPreorder traversal of binary tree is \n";
	preorder(root);

	cout << "\nInorder traversal of binary tree is \n";
	inorder(root);

	cout << "\nPostorder traversal of binary tree is \n";
	postorder(root);


}













