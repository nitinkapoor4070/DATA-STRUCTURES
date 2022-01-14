
#include<bits/stdc++.h>

using namespace std;



class Node
{

public:

    int key;

    Node *left;

    Node *right;

    int height;
};


int max(int a, int b);



int height(Node *N)
{

    if (N == NULL)

        return 0;

    return N->height;
}



int max(int a, int b)
{

    return (a > b) ? a : b;
}



Node* newNode(int key)
{

    Node* node = new Node();

    node->key = key;

    node->left = NULL;

    node->right = NULL;

    node->height = 1;



    return (node);
}


Node *rightRotate(Node *y)
{

    Node *x = y->left;

    Node *T2 = x->right;




    x->right = y;

    y->left = T2;




    y->height = max(height(y->left),

                    height(y->right)) + 1;

    x->height = max(height(x->left),

                    height(x->right)) + 1;




    return x;
}


Node *leftRotate(Node *x)
{

    Node *y = x->right;

    Node *T2 = y->left;




    y->left = x;

    x->right = T2;



    x->height = max(height(x->left),

                    height(x->right)) + 1;

    y->height = max(height(y->left),

                    height(y->right)) + 1;




    return y;
}


int getBalance(Node *N)
{

    if (N == NULL)

        return 0;

    return height(N->left) - height(N->right);
}


Node* insert(Node* node, int key)
{



    if (node == NULL)

        return (newNode(key));


    if (key < node->key)

        node->left = insert(node->left, key);

    else if (key > node->key)

        node->right = insert(node->right, key);

    else // Equal keys are not allowed in BST

        return node;




    node->height = 1 + max(height(node->left),

                           height(node->right));




    int balance = getBalance(node);





    // Left Left Case

    if (balance > 1 && key < node->left->key)

        return rightRotate(node);


    // Right Right Case

    if (balance < -1 && key > node->right->key)

        return leftRotate(node);


    // Left Right Case

    if (balance > 1 && key > node->left->key)

    {

        node->left = leftRotate(node->left);

        return rightRotate(node);

    }


    // Right Left Case

    if (balance < -1 && key < node->right->key)

    {

        node->right = rightRotate(node->right);

        return leftRotate(node);

    }




    return node;
}



void preOrder(Node *root)
{

    if (root != NULL)

    {

        cout << root->key << " ";

        preOrder(root->left);

        preOrder(root->right);

    }
}


int main()
{
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("out.txt", "w", stdout);
#endif
    Node *root = NULL;





    root = insert(root, 100);

    root = insert(root, 200);

    root = insert(root, 300);

    root = insert(root, 400);

    root = insert(root, 500);

    root = insert(root, 250);



    /* The constructed AVL Tree would be

                300

            / \

            200 400

            / \ \

        100 250 500

    */

    cout << "Preorder traversal of the "

         "constructed AVL tree is \n";

    preOrder(root);

    return 0;
}