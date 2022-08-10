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

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
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

bool searchInBST(Node *root, int x)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }

    if ((root->data) > x)
        return searchInBST(root->left, x);
    else
        return searchInBST(root->right, x);
}
int main()
{

    //    SEARCH IN A BINARY SEARCH TREE

    // TIME COMPLEXITY :- O(LOG(N))

    int n = 7;

    int arr[n] = {1, 2, 3, 4, 5, 6, 7};

    Node *root = construct(arr, 0, n - 1);

    // inorder(root);

    int x;
    cin >> x;
    if (searchInBST(root, x))
    {
        cout << "ELEMENT FOUND" << endl;
    }
    else
    {
        cout << "ELEMENT NOT FOUND" << endl;
    }
}

