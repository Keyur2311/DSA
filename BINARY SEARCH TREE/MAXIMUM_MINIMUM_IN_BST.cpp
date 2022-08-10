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

int maximumInBST(Node *root)
{
    int maxi = -1;
    while (root != NULL)
    {
        maxi = root->data;
        root = root->right;
    }
    return maxi;
}

int minimunInBST(Node *root)
{
    int mini = -1;
    while (root != NULL)
    {
        mini = root->data;
        root = root->left;
    }
    return mini;
}
int main()
{

    //  MAX AND MIN VALUE IN A BINARY SEARCH TREE

    // TIME COMPLEXITY :- O(H) OR(O(LOG(N)) ( H= HEIGHT OF BINARY SEARCH TREE)

    int n = 7;

    int arr[n] = {1, 2, 4, 5, 6, 8, 10};

    Node *root = construct(arr, 0, n - 1);

    cout << maximumInBST(root) << endl;
    cout << minimunInBST(root) << endl;
}

