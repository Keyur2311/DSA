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

int ceilInBST(Node *root, int x)
{
    int ceil = -1;

    while (root)
    {
        if (root->data == x)
        {
            ceil = root->data;
            return ceil;
        }

        if (x > root->data)
        {
            root = root->right;
        }
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }

    return ceil;
}
int main()
{

    //   CEIL IN A BINARY SEARCH TREE

    // CEIL :- VALUE >= KEY (SMALLEST NUMBER PRESENT IN BST WHICH IS GREATER THAN EQUAL TO KEY)

    // TIME COMPLEXITY :- O(LOG(N))

    int n = 7;

    int arr[n] = {1, 2, 4, 5, 6, 7, 10};

    Node *root = construct(arr, 0, n - 1);

    int x;
    cin >> x;

    cout << ceilInBST(root, x) << endl;
}

