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

bool isMirrorStructure(Node *l, Node *r)
{
    if (l == NULL && r == NULL)
        return true;
    if (l == NULL || r == NULL)
        return false;

    return isMirrorStructure(l->left, r->right) && isMirrorStructure(l->right, r->left);
}
bool isFoldable(Node *&root)
{
    if (root == NULL)
        return true;

    return isMirrorStructure(root->left, root->right);
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

    //          BINARY TREE IS FOLDABLE OR NOT

    // TIME COMPLEXITY :- O(N)
    // AUXILIARY SPACE :- O(1)

    if (isFoldable(root))
    {
        cout << "FOLDABLE" << endl;
    }
    else
    {
        cout << "NOT FOLDABLE" << endl;
    }
}

