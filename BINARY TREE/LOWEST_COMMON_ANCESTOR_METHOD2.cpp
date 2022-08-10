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
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (root == NULL || root == p || root == q)
    {
        return root;
    }

    Node *left = lowestCommonAncestor(root->left, p, q);
    Node *right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;

    else
    { //both left and right are not null, we found our result
        return root;
    }
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

    //          LOWEST COMMON ANCESTOR OF TWO NODES IN BINARY TREE
    // METHOD 2 : USING DFS
    // TIME COMPLEXITY :- O(N)
    // AUXILIARY SPACE :- O(1) ( OPTIMIZED)

    Node *LCA = lowestCommonAncestor(root, root->left->left, root->left->right);

    cout << LCA->data << endl;
}

