#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int maxi = INT_MIN;

int maxPathSum(Node *&root)
{
    if (root == NULL)
        return 0;

    int maxleft = max(0, maxPathSum(root->left));
    int maxright = max(0, maxPathSum(root->right));
    maxi = max(maxi, maxleft + maxright + root->data);

    return root->data + max(maxleft, maxright);
}
int main()
{

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    maxPathSum(root);
    cout << "MAXIMUM PATH SUM IS:- "<< maxi << endl;
}

