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

void inorder(Node *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
int main()
{

    //  TARGET SUM PAIR  (METHOD:-2  OPTIMIZED)
    // TIME COMPLEXITY  :- O(N)
    // SPACE COMPLEXITY :- O(N)

    int n = 9;

    int arr[n] = {20, 30, 35, 40, 45, 50, 70, 80, 100};

    Node *root = construct(arr, 0, n - 1);

    int target = 70;
    // cin>>target;

    vector<int> in;
    inorder(root, in);

    int left = 0;
    int right = in.size() - 1;

    while (left < right)
    {
        if (in[left] + in[right] > target)
        {
            right--;
        }
        else if (in[left] + in[right] < target)
        {
            left++;
        }
        else
        {
            cout << in[left] << " " << in[right] << endl;
            left++;
            right--;
        }
    }
}

