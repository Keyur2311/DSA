
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
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool searchInBT(Node *&root, int x)
{
   if(root == NULL) return false;

   if(root->data == x) return true;

    return searchInBT(root->left, x) || searchInBT(root->right, x);
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

    int x;
    cin >> x;

    if (searchInBT(root, x))
    {
        cout << "ELEMENT FOUND" << endl;
    }
    else
    {
        cout << "ELEMENT NOT FOUND" << endl;
    }
}

