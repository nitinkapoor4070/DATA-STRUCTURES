#include<iostream>
#include<vector>
#include<queue>

using namespace std;

template<typename T>
class treenode {

public:
	T data;
	vector<treenode<T>*> children;

	treenode(T data) {
		this->data = data;
	}
	~treenode() {
		for (int i = 0; i < children.size(); i++)
			delete children[i];
	}

};


/*treenode<int>* takeinput() {
	int rootdata;
	cout << "enter data" << endl;
	cin >> rootdata;
	treenode<int>* root = new treenode<int>(rootdata);

	int n;
	cout << "enter number of children of " << rootdata << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		treenode<int>* child = takeinput();
		root->children.push_back(child);
	}
	return root;

}*/


treenode<int>* inputlevelwise() {
	int rootdata;
	cout << "enter data" << endl;
	cin >> rootdata;
	treenode<int>* root = new treenode<int>(rootdata);
	queue<treenode<int>*> pendingnotes;

	pendingnotes.push(root);
	while (pendingnotes.size() != 0) {
		treenode<int>* front = pendingnotes.front();
		pendingnotes.pop();
		cout << "enter number of children of " << front->data << endl;
		int numchild;
		cin >> numchild;
		for (int i = 0; i < numchild; i++) {
			int childdata;
			cout << "enter" << i << "th child of" << front->data << endl;
			cin >> childdata;
			treenode<int>* child = new treenode<int>(childdata);
			front->children.push_back(child);
			pendingnotes.push(child);
		}

	}
	return root;
}

/*

void printtree(treenode<int>* root) {
	if (root == NULL)
		return;
	cout << root->data << ":" ;
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ",";
	}
	cout << endl;

	for (int i = 0; i < root->children.size(); i++) {
		printtree(root->children[i]);
	}
}
*/

void printtreelinewise(treenode<int>* root) {
	if (root == NULL)
		return;
	queue<treenode<int>*> pendingnotes;
	pendingnotes.push(root);
	while (pendingnotes.size() != 0) {
		treenode<int>* front = pendingnotes.front();
		pendingnotes.pop();


		cout << front->data << ":" ;
		for (int i = 0; i < front->children.size(); i++) {
			cout << front->children[i]->data << ",";
			pendingnotes.push(front->children[i]);
		}
		cout << endl;


	}
}


int numnodes(treenode<int>* root) {
	if (root == NULL)
		return 0;
	int ans = 1;
	for (int i = 0; i < root->children.size(); i++)
		ans += numnodes(root->children[i]);
	return ans;
}

void printallevelk(treenode<int>* root, int k) {
	if (root == NULL)
		return;
	if (k == 0) {
		cout << root->data << endl;
		return;
	}
	for (int i = 0; i < root->children.size(); i++)
		printallevelk(root->children[i], k - 1);
}

int numleafnodes(treenode<int>* root) {
	if (root == NULL)
		return 0;
	int ans = 0;
	if (root->children.size() == 0) {
		ans = 1;
		return ans;
	}
	for (int i = 0; i < root->children.size(); i++)
		ans += numleafnodes(root->children[i]);
	return ans;
}

void deletetree(treenode<int>* root) {
	for (int i = 0; i < root->children.size(); i++)
		deletetree(root->children[i]);

	delete root;

}



int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	/*
		treenode<int>* root = new treenode<int>(1);
		treenode<int>* node1 = new treenode<int>(2);
		treenode<int>* node2 = new treenode<int>(3);

		root->children.push_back(node1);
		root->children.push_back(node2);
		printtree(root);
	*/
	treenode<int>* root = inputlevelwise();
	printtreelinewise(root);
	cout << endl;
	cout << numleafnodes(root);

	delete root;




}