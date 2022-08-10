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

int leftHeight(Node *root)
{
    int h = 1;
    while (root)
    {
        h++;
        root = root->left;
    }
    return h;
}

int rightHeight(Node *root)
{
    int h = 1;
    while (root)
    {
        h++;
        root = root->right;
    }
    return h;
}

int countNodes(Node *root)
{
    if (root == NULL)
        return 0;

    int l = leftHeight(root->left);
    int r = rightHeight(root->right);

    //if leftHeight and rightHeight is equal then we can say that subtree is completely filled
    // means that subtree has 2^h - 1 nodes
    // so we don't travel that subtree and  directly return 2^h-1
    if (l == r)
        return (1 << l) - 1;

    else
        return 1 + countNodes(root->left) + countNodes(root->right);
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

    //    COUNT NODES IN COMPLETE BINARY TREE IN LESS THAN O(N) TIME

    // TIME COMPLEXITY :- LESS THAN O(N) (MAY BE O(LOG(N))

    int totalNodes = countNodes(root);

    cout << totalNodes << endl;
}

