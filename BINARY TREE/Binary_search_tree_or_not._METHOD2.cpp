#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *pre = NULL;
bool isBST(Node *root)
{
    if (root == NULL)
        return true;

    if (!isBST(root->left))
        return false;

    if (pre != NULL && pre->data >= root->data)
        return false;

    pre = root;

    if (!isBST(root->right))
        return false;

    return true;
}

int main()
{

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    //                  BINARY TREE IS BST OR NOT(USING INORDER PROPERTY) ?
    // NOTE:-  BINARY SEARCH TREE'S INORDER IS ALWAYS SORTED IN INCREASING ORDER

    // SPACE COMPLEXITY = O(1)  <---(WITHOUT CONSIDERING CALL STACK) ELSE O(N)
    // TIME COMPLEXITY  = O(N)

    if (isBST(root))
    {
        cout << "BINARY TREE IS BST" << endl;
    }
    else
    {
        cout << "BINARY TREE IS NOT BST" << endl;
    }
}


