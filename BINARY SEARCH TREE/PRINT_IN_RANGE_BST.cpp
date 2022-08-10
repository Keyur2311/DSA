
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

void printInRange(Node *root, int l, int r)
{
    if (root == NULL)
        return;
    if (l < root->data && r < root->data)
    {
        printInRange(root->left, l, r);
    }
    else if (l > root->data && r > root->data)
    {
        printInRange(root->right, l, r);
    }
    else
    {
        printInRange(root->left, l, r);
        cout << root->data << " ";
        printInRange(root->right, l, r);
    }
}
int main()
{

    // PRINT IN RANGE BST
    // TIME COMPLEXITY :- O(N)

    int n = 9;

    int arr[n] = {15, 30, 35, 40, 45, 50, 70, 80, 100};

    Node *root = construct(arr, 0, n - 1);

    printInRange(root, 31, 81);
}
