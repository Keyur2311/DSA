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
Node *rightMost(Node *root)
{

    if (root->right == NULL)
    {
        return root;
    }

    return rightMost(root->right);
}
Node *helper(Node *root)
{
    if (root->left == NULL)
    {
        return root->right;
    }
    if (root->right == NULL)
    {
        return root->left;
    }

    Node *rightChild = root->right;
    Node *lastRight = rightMost(root->left);

    lastRight->right = rightChild;

    return root->left;
}
Node *deleteNodeBST(Node *&root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == x)
    {
        return helper(root);
    }

    Node *temp = root;

    while (root)
    {

        if (root->data > x)
        {
            if (root->left != NULL && root->left->data == x)
            {
                root->left = helper(root->left);
                break;
            }
            else
            {
                root = root->left;
            }
        }

        else
        {
            if (root->right != NULL && root->right->data == x)
            {
                root->right = helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }

    return temp;
}

int main()
{

    // DELETE A NODE IN A BINARY SEARCH TREE

    // TIME COMPLEXITY :- O(LOGN)

    int n = 7;

    int arr[n] = {1, 2, 4, 5, 6, 8, 10};

    Node *root = construct(arr, 0, n - 1);

    preorder(root);
    cout << endl;
    Node *root1 = deleteNodeBST(root, 5);
    preorder(root1);
}
