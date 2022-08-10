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

struct Pair
{
    Node *node;
    int hd;
};

map<int, vector<int>> mp;
void verticalorder(Node *&root)
{
    queue<Pair> q;
    int hd = 0;
    q.push({root, hd});

    while (q.size() > 0)
    {
        Pair p = q.front();
        q.pop();

        Node *temp = p.node;
        mp[p.hd].push_back(temp->data);

        if (temp->left != NULL)
        {
            q.push({temp->left, p.hd - 1});
        }

        if (temp->right != NULL)
        {
            q.push({temp->right, p.hd + 1});
        }
    }
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

    // <----- VERTICAL ORDER TRAVERSAL (VERSION 2) (ITERATIVE)----->
    // ALL THE NODES IN EVERY VECTOR ARE SORTED LEVELWISE
    // TIME COMPLEXITY :- O(N);

    verticalorder(root);

    for (auto it : mp)
    {
        for (auto i : it.second)
        {
            cout << i << " ";
        }

        cout << endl;
    }
}

