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

void preorder(Node *root, vector<int> &v)
{
    if (root != NULL)
    {
        v.push_back(root->data);
        preorder(root->left, v);
        preorder(root->right, v);
    }
    else
    {
        v.push_back(100000);
    }
}
void inorder(Node *root, vector<int> &v)
{
    if (root != NULL)
    {
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    else
    {
        v.push_back(100000);
    }
}

bool isSameBT(Node *&p, Node *&q)
{
    vector<int> v1in, v1pre;
    inorder(p, v1in);
    preorder(p, v1pre);

    vector<int> v2in, v2pre;
    inorder(q, v2in);
    preorder(q, v2pre);

    if (v1in == v2in && v1pre == v2pre)
    {
        return true;
    }
    return false;
}
int main()
{

    struct Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    struct Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(6);
    root2->right->right = new Node(7);

    if (isSameBT(root1, root2))
    {
        cout << " BINARY TREES ARE SAME " << endl;
    }
    else
    {
        cout << " NOT SAME " << endl;
    }
}

