#include <iostream>
#include <climits>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    BinaryTreeNode<int>* root;

    bool search(BinaryTreeNode<int>* root, int data) {
        if (root == NULL) {
            return false;
        }
        if (root->data == data) {
            return true;
        } else if (root->data > data) {
            return search(root->left, data);
        } else {
            return search(root->right, data);
        }
    }

    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* root, int data) {
        if (root == NULL) {
            BinaryTreeNode<int>* node = new BinaryTreeNode<int>(data);
            return node;
        }
        if (data <= root->data) {
            BinaryTreeNode<int>* left = insert(root->left, data);
            root->left = left;
        } else {
            BinaryTreeNode<int>* right = insert(root->right, data);
            root->right = right;
        }
        return root;
    }

    int minimum(BinaryTreeNode<int>* root) {
        if (root == NULL) {
            return INT_MAX;
        }
        return min(root->data , min(minimum(root->left), minimum(root->right)));
    }

    BinaryTreeNode<int>* remove(BinaryTreeNode<int>* root, int data) {
        if (root == NULL) {
            return NULL;
        }
        if (root->data == data) {
            if (root->left == NULL && root->right == NULL) {
                return NULL;
            } else if (root->left != NULL && root->right == NULL) {
                BinaryTreeNode<int>* left = root->left;
                delete root;
                return left;
            } else if (root->right != NULL && root->left == NULL) {
                BinaryTreeNode<int>* right = root->right;
                delete root;
                return right;
            } else if (root->left != NULL && root->right != NULL) {
                //calculate min BST iterative.
                BinaryTreeNode<int>* curr = root->right;
                while (curr->left != NULL) {
                    curr = curr->left;
                }
                int minRight = curr->data;
                root->data = minRight;
                BinaryTreeNode<int>* newRight = remove(root->right, minRight);
                root->right = newRight;
                return root;
            }
        } else if (root->data > data) {
            BinaryTreeNode<int>* left = remove(root->left, data);
            root->left = left;
            return root;
        } else {
            BinaryTreeNode<int>* right = remove(root->right, data);
            root->right = right;
            return root;
        }

        return root;
    }

    void print(BinaryTreeNode<int>* root) {
        if (root == NULL) {
            return;
        }
        cout << root->data << ":";
        if (root->left) {
            cout << "L:" << root->left->data << ",";
        }
        if (root->right) {
            cout << "R:" << root->right->data;
        }
        cout << endl;
        print(root->left);
        print(root->right);
    }
public:
    BST() {
        root = NULL;
    }
    ~BST() {
        delete root;
    }

    void remove(int data) {
        this->root = remove(root, data);
    }

    void print() {
        print(root);
    }

    void insert(int data) {
        this->root = insert(root, data);
    }

    bool search(int data) {
        return search(root, data);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("out.txt", "w", stdout);
#endif

    BST *tree = new BST();
    tree->insert(100);
    tree->insert(10);
    tree->insert(400);
    tree->insert(300);
    tree->insert(500);
    tree->insert(700);
    tree->insert(600);
    tree->insert(800);
    tree->print();
    /* Tree that will be printed
           100
          /  \
         10   400
             /  \
            300   500
                  \
                   700
                  /  \
                 600   800
          */
}