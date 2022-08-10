#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node() {}

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

Node *pre = NULL;
void flatten(Node *&root)
{

    if (root == NULL)
        return;

    flatten(root->right);
    flatten(root->left);

    root->right = pre;
    root->left = NULL;
    pre = root;
}

int main()
{

    // FLATTEN A BINARY TREE INTO  LINKEDLIST (METHOD 1 : RECURSIVE)

    // TIME COMPLEXITY:- O(N)

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    preorder(root);
    cout << endl;

    flatten(root);
    preorder(root);
}

