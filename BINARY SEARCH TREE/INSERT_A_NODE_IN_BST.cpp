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
Node *insertNodeBST(Node *&root, int x)
{
    if (root == NULL)
    {
        root = new Node(x);
        return root;
    }

    Node *temp = root;

    while (1)
    {
        if (temp->data <= x)
        {
            if (temp->right != NULL)
            {
                temp = temp->right;
            }
            else
            {
                temp->right = new Node(x);
                break;
            }
        }
        else
        {
            if (temp->left != NULL)
            {
                temp = temp->left;
            }
            else
            {
                temp->left = new Node(x);
                break;
            }
        }
    }

    return root;
}

int main()
{

    // INSERT A NODE IN A BINARY SEARCH TREE

    int n = 7;

    int arr[n] = {1, 2, 4, 5, 6, 8, 10};

    Node *root = construct(arr, 0, n - 1);

    preorder(root);
    cout << endl;
    Node *root1 = insertNodeBST(root, 9);
    preorder(root1);
}
