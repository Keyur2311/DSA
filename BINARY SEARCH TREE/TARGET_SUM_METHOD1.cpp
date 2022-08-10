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

bool find(Node *root, int key)
{

    if (root == NULL)
    {
        return false;
    }

    if (key > root->data)
    {
        return find(root->right, key);
    }
    else if (key < root->data)
    {
        return find(root->left, key);
    }
    else
    {
        return true;
    }
}

void targetSumSubest(Node *root, Node *node, int target)
{
    if (node == NULL)
        return;

    targetSumSubest(root, node->left, target);
    if (node->data < target)
    {
        int rem = target - node->data;
        if (rem > node->data)
        {
            if (find(root, rem))
            {
                cout << node->data << " " << rem << endl;
            }
        }
    }
    targetSumSubest(root, node->right, target);
}
int main()
{

    //  TARGET SUM PAIR  (METHOD 1 -> NOT OPTIMIZED)
    // TIME COMPLEXITY  :- O(N*LOGN)
    // SPACE COMPLEXITY :- O(LOGN) (FOR CALL STACK)

    int n = 9;

    int arr[n] = {20, 30, 35, 40, 45, 50, 70, 80, 100};

    Node *root = construct(arr, 0, n - 1);

    targetSumSubest(root, root, 70);
}

