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

bool getPath(Node *&root, int des, vector<int> &v)
{
    if (root == NULL)
        return false;

    v.push_back(root->data);

    if (root->data == des)
        return true;

    if (getPath(root->left, des, v) || getPath(root->right, des, v))
        return true;

    v.pop_back();
    return false;
}

vector<int> rootToNodePath(Node *&root, int des)
{
    vector<int> v;
    if (root == NULL)
    {
        return v;
    }
    getPath(root, des, v);
    return v;
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
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    // <----- ROOT TO NODE PATH (IMPORTANT QUESTION) ----->

    // TIME  COMPLEXITY :- O(N)
    // SPACE COMPLEXITY :- O(N)

    int des;
    cin >> des;

    vector<int> v = rootToNodePath(root, des);
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}
