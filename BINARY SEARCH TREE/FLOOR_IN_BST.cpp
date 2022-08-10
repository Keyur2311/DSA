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

int floorInBST(Node *root, int x)
{
    int floor = -1;

    while (root)
    {
        if (root->data == x)
        {
            floor = root->data;
            return floor;
        }

        if (x > root->data)
        {
            floor = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    return floor;
}
int main()
{

    //  FLOOR IN A BINARY SEARCH TREE

    // FLOOR :- VALUE <= KEY (GREATEST ELEMENT PRESENT IN BST WHICH IS SMALLER THAN OR EQUAL TO KEY)

    // TIME COMPLEXITY :- O(LOG(N))

    int n = 7;

    int arr[n] = {1, 2, 4, 5, 6, 8, 10};

    Node *root = construct(arr, 0, n - 1);

    int x;
    cin >> x;

    cout << floorInBST(root, x) << endl;
}

