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

bool rootToNodePath(Node *root, int des, vector<int> &v)
{
    if (root == NULL)
        return false;

    v.push_back(root->data);

    if (root->data == des)
    {
        return true;
    }

    if (rootToNodePath(root->left, des, v) || rootToNodePath(root->right, des, v))
        return true;

    v.pop_back();
    return false;
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

    //          LOWEST COMMON ANCESTOR OF TWO NODES IN BINARY TREE
    // METHOD 1 : (BRUTE FORCE)
    // TIME COMPLEXITY :- O(N)
    // AUXILIARY SPACE :- O(N) (EXTRA SPACE (NOT OPTIMIZED))

    int x, y;
    cin >> x >> y;

    vector<int> v1, v2;

    rootToNodePath(root, x, v1);
    rootToNodePath(root, y, v2);

    int ans = 0;

    for (int i = 0; i < min((int)v1.size(), (int)v2.size()); i++)
    {
        if (v1[i] == v2[i])
            ans = v1[i];
    }

    cout << ans << endl;
}

