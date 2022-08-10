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
int height(Node *root)
{
    if (root == NULL)
        return 0; // return -1 in terms of edges , return 0 in terms of nodes

    int lh = height(root->left);
    int rh = height(root->right);
    int mh = max(lh, rh) + 1;
    return mh;
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

    // <----- HEIGHT OF A BINARY TREE ----->

    // TIME COMPLEXITY :- O(N)
    // AUXIALIARY SPACE  :- O(1)

    cout << height(root) << endl;
}
