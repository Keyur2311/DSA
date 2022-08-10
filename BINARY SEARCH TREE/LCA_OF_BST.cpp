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

Node *construct(int arr[], int lo, int hi)
{
    if (lo > hi)
        return NULL;

    int mid = (lo + hi) / 2;
    Node *node = new Node(arr[mid]);
    node->left = construct(arr, lo, mid - 1);
    node->right = construct(arr, mid + 1, hi);

    return node;
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        preorder(root->left);
        cout << root->data << " ";
        preorder(root->right);
    }
}

int LCAofBST(Node *root, int d1, int d2)
{
    if (d1 > root->data && d2 > root->data)
    {
        return LCAofBST(root->right, d1, d2);
    }
    else if (d1 < root->data && d2 < root->data)
    {
        return LCAofBST(root->left, d1, d2);
    }
    else
    {
        return root->data;
    }
}
int main()
{

    // LCA OF BST
    // TIME COMPLEXITY :- O(LOGN)

    int n = 7;

    int arr[n] = {1, 2, 4, 5, 6, 8, 10};

    Node *root = construct(arr, 0, n - 1);

    cout << LCAofBST(root, 6, 10) << endl;
}

