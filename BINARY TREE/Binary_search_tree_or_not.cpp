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

struct BSTPair
{
    bool isBST;
    int min;
    int max;
};

BSTPair isBSTREE(Node *&root)
{

    if (root == NULL)
    {
        BSTPair bp;
        bp.isBST = true;
        bp.min = INT_MAX;
        bp.max = INT_MIN;
        return bp;
    }
    BSTPair lp = isBSTREE(root->left);
    BSTPair rp = isBSTREE(root->right);

    BSTPair mp;
    mp.isBST = lp.isBST && rp.isBST && (root->data >= lp.max) && (root->data <= rp.min);
    mp.min = min(root->data, min(lp.min, rp.min));
    mp.max = max(root->data, max(lp.max, rp.max));

    return mp;
}
int main()
{

    struct Node *root = new Node(50);
    root->left = new Node(25);
    root->right = new Node(75);
    root->left->left = new Node(12);
    root->left->right = new Node(37);
    root->right->left = new Node(62);
    root->right->right = new Node(87);

    //<----- BINARY TREE IS BST OR NOT ----->
    // TIME COMPLEXITY :- O(N)
    // AUXILIARY SPACE :- O(1) ( WITHOUT CONSIDERING CALL STACK OTHERWISE SPACE IS O(N))

    BSTPair bp = isBSTREE(root);


    if (bp.isBST)
    {
        cout << "THIS IS A BINARY SEARCH TREE" << endl;
    }
    else
    {
        cout << "NOT A BINARY SEARCH TREE" << endl;
    }
}

