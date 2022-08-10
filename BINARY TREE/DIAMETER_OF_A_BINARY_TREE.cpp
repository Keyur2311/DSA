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

int dia = 0;
int height(Node *root)
{

    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);

    dia = max(dia, lh + rh);

    return max(lh, rh) + 1;
}

int main()
{

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(10);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    root->right->right->right->left = new Node(9);

    // <----- DIAMETER OF A BINARY TREE  ----->

    // TIME  COMPLEXITY :- O(N)  (OPTIMIZED)
    // SPACE COMPLEXITY :- O(N)

    int x = height(root);

    cout << dia << endl;
}
