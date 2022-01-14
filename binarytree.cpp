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

void printtree(binarytreenode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << ':';
	if (root->left != NULL) {
		cout << "L" << root->left->data;
	}
	if (root->right != NULL) {
		cout << "R" << root->right->data;
	}
	cout << endl;
	printtree(root->left);
	printtree(root->right);
}

binarytreenode<int>* takeinputlevelwise() {
	int rootdata;
	cout << "enter root data" << endl;
	cin >> rootdata;
	if (rootdata == -1) {
		return NULL;
	}
	binarytreenode<int>* root = new binarytreenode<int>(rootdata);
	queue<binarytreenode<int>*> pendingnotes;
	pendingnotes.push(root);
	while (pendingnotes.size() != 0) {
		binarytreenode<int>* front = pendingnotes.front();
		pendingnotes.pop();
		cout << "enter left child of" << front->data << endl;
		int leftchilddata;
		cin >> leftchilddata;
		if (leftchilddata != -1) {
			binarytreenode<int>* child = new binarytreenode<int>(leftchilddata);
			front->left = child;
			pendingnotes.push(child);
		}
		cout << "enter right child of" << front->data << endl;
		int rightchilddata;
		cin >> rightchilddata;
		if (rightchilddata != -1) {
			binarytreenode<int>* child = new binarytreenode<int>(rightchilddata);
			front->right = child;
			pendingnotes.push(child);

		}
	}

	return root;
}



binarytreenode<int>* takeinput() {
	int rootdata;
	cout << "enter data" << endl;
	cin >> rootdata;
	if (rootdata == -1) {
		return NULL;
	}
	binarytreenode<int>* root = new binarytreenode<int>(rootdata);
	binarytreenode<int>* leftchild = takeinput();
	binarytreenode<int>* rightchild = takeinput();
	root->left = leftchild;
	root->right = rightchild;
	return root;
}


int numnodes(binarytreenode<int>* root) {
	if (root == NULL)
		return 0;

	return 1 + numnodes(root->left) + numnodes(root->right);
}

void inorder(binarytreenode<int> *root) {
	if (root == NULL) {
		return;

	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

binarytreenode<int>* buildtreehelper(int*in , int* pre, int inS, int inE, int preS, int preE) {
	if (inS > inE) {
		return NULL;
	}
	int rootdata = pre[preS];
	int rootindex = -1;
	for (int i = inS; i <= inE; i++) {
		if (in[i] == rootdata) {
			rootindex = i;
			break;
		}
	}
	int lpreS = preS + 1;

	int linS = inS;
	int linE = rootindex - 1;
	int lpreE = linE - linS + lpreS;
	int rpreS = lpreE + 1;
	int rpreE = preE;
	int rinS = rootindex + 1;
	int rinE = inE;

	binarytreenode<int>* root = new binarytreenode<int>(rootdata);
	root->left = buildtreehelper(in, pre, linS, linE, lpreS, lpreE);
	root->right = buildtreehelper(in, pre, rinS, rinE, rpreS, rpreE);
	return root;
}


binarytreenode<int>* buildtree(int* in, int* pre, int size) {
	return buildtreehelper(in, pre, 0, size - 1, 0, size - 1);
}

int height(binarytreenode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}

int diameter(binarytreenode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	int opt1 = height(root->left) + height(root->right);
	int opt2 = diameter(root->left);
	int opt3 = diameter(root->right);
	return max(opt1, max(opt2, opt3));
}

pair<int, int> heightdiameter(binarytreenode<int>* root) {
	if (root == NULL) {
		pair<int, int> p;
		p.first = 0;
		p.second = 0;

		return p;
	}
	pair<int, int> leftans = heightdiameter(root->left);
	pair<int, int> rightans = heightdiameter(root->right);
	int ld = leftans.second;
	int lh = leftans.first;
	int rd = rightans.second;
	int rh = rightans.first;

	int height = 1 + max(lh, rh);
	int diameter = max(lh + rh, max(ld, rd));
	pair<int, int> p;
	p.first = height;
	p.second = diameter;
	return p;
}


/*1
2
3
4
5
6
7
-1
-1
8
9
-1
-1
-1
-1
-1
-1
-1
-1
*/
int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("out.txt", "w", stdout);
#endif

	//binarytreenode<int>* root = takeinputlevelwise();
	int in[] = {4, 10, 12, 15, 18, 22, 24, 25, 31, 35, 44, 50, 66, 70, 90};
	int pre[] = {25, 15, 10, 4, 12, 22, 18, 24, 50, 35, 31, 44, 70, 66, 90};
	//buildtree(in, pre, 15);

	printtree(buildtree(in, pre, 15));


	/*cout << "number of nodes" << numnodes(root);
	pair<int, int> p = heightdiameter(root);
	cout << endl;
	cout << "h" << p.first << endl;
	cout << "d" << p.second << endl;*/
}

