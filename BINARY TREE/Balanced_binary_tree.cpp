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

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
bool isBal = true;
int isBalanced(Node *root)
{

    if (root == NULL)
        return 0;

    int lh = isBalanced(root->left);
    int rh = isBalanced(root->right);

    int gap = abs(lh - rh);

    if (gap > 1)
    {
        isBal = false;
    }

    return max(lh, rh) + 1;
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
    root->right->right->right = new Node(8);
    root->right->right->right->right = new Node(9);


    //<-----  BALANCED BINARY TREE OR NOT  ----->
    // TIME COMPLEXITY = O(N);
    // SPACE COMPLEXITY = O(1);

    
    isBalanced(root);
    isBal == true ? cout << " BALANCED BINARY TREE" : cout << " NOT BALANCED " << endl;
}
