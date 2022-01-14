#include<iostream>
#include<string>
using namespace std;


class trinode {
public:
	char data ;
	trinode** children;
	bool isterminal;

	trinode(char data) {
		this->data = data;
		children = new trinode*[26];
		for (int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isterminal = false;
	}
};

class trie {
	trinode *root;
public:
	trie() {
		root = new trinode('\0');

	}
public:
	void insertword(trinode *root, string word) {
		if (word.size() == 0) {
			root->isterminal = true;
			return;
		}
		int index = word[0] - 'a';
		trinode *child;
		if (root->children[index] != NULL) {
			child = root->children[index];
		}
		else {
			child = new trinode(word[0]);
			root->children[index] = child;
		}
		insertword(child, word.substr(1));
	}

	void insertword(string word) {
		insertword(root, word);
	}

	bool search(trinode *root, string word) {

		if (word.size() == 0) {
			return root->isterminal;
		}
		int index = word[0] - 'a';
		trinode *child;
		if (root->children[index] != NULL) {
			child = root->children[index];
		}
		else {
			return false;
		}
		return search(child, word.substr(1));
	}

	bool search(string word) {
		return search(root, word);
	}

	void removeword(trinode *root, string word) {
		if (word.size() == 0) {
			root->isterminal = false;
			return;
		}
		trinode *child;
		int index = word[0] - 'a';
		if (root->children[index] != NULL) {
			child = root->children[index];
		}
		else {
			return;
		}
		removeword(child, word.substr(1));
		if (child->isterminal == false) {
			for (int i = 0; i < 26; i++) {
				if (child->children[i] != NULL) {
					return;
				}
			}
			delete child;
			root->children[index] = NULL;
		}
	}


	void removeword(string word) {
		removeword(root, word);
	}
};

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("out.txt", "w", stdout);
#endif

	trie t;
	t.insertword("and");
	t.insertword("are");
	t.insertword("dot");
	cout << t.search("and") << endl;
	t.removeword("and");
	cout << t.search("and") << endl;

}









