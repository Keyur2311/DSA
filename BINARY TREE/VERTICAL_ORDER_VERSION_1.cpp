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

map<int, vector<int>> mp;
void verticalorder(Node *&root, int hd)
{
    if (root == NULL)
        return;

    verticalorder(root->left, hd - 1);
    mp[hd].push_back(root->data);
    verticalorder(root->right, hd + 1);
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

    // <----- VERTICAL ORDER TRAVERSAL (VERSION 1) (RECURSIVE)----->
    // TIME COMPLEXITY :- O(N);

    // IN THIS QUESTION, IN EVERY HORIZONTAL DISTANCE'S VECTOR IT IS NOT NECESSARY THAT ALL NODES MUST BE IN ORDER (LEVEL ORDER)

    // 2ND VERSION OF THIS QUE CONTAINS LEVEL ORDER
    verticalorder(root, 0);

    for (auto it : mp)
    {
        for (auto i : it.second)
        {
            cout << i << " ";
        }

        cout << endl;
    }
}

