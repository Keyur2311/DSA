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


int mn = INT_MAX, mx = INT_MIN;
void shadow_Width(Node *&root, int hd)
{
    if (root == NULL)
        return;
    shadow_Width(root->left, hd - 1);
    mn = min(mn, hd);
    mx = max(mx, hd);
    shadow_Width(root->right, hd + 1);
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

    //  WIDTH OF SHADOW OF A BINARY TREE
    // TIME COMPLEXITY :- O(N)
    // AUXILIARY SPACE :- O(1)  (For call stack O(N))

    shadow_Width(root, 0);

    cout << "WIDTH OF SHADOW IS " << mx - mn + 1 << endl;
}

