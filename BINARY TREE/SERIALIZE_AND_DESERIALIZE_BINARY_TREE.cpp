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

// serialization of a Binary tree from preorder
void serialize(Node *&root, vector<int> &v)
{
    if (root == NULL)
    {
        v.push_back(-1);
        return;
    }

    v.push_back(root->data);
    serialize(root->left, v);
    serialize(root->right, v);
}

// Deserialization of a binary tree and returning root of that Binary tree
int idx = 0;
Node *deserialize(vector<int> v)
{
    if (idx >= (v.size()) || v[idx] == -1)
    {
        idx++;
        return NULL;
    }
    Node *node = new Node(v[idx++]);
    node->left = deserialize(v);
    node->right = deserialize(v);

    return node;
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

    // <----- SERIALIZE A BINARY TREE (USING PREORDER) ------>
    // TIME COMPLEXITY :- O(N)
    // SPACE COMPLEXITY :- O(N)

    vector<int> v;
    serialize(root, v);

    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;

    // <----- DESERIALIZE A BINARY TREE ----->
    Node *node = deserialize(v);
    cout << (node->data) << endl;

}

