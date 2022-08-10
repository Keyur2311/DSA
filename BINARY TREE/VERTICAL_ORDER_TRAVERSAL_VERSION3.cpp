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

int mx = INT_MIN, mn = INT_MAX;

void shadow_width(Node *&root, int hd)
{
    if (root == NULL)
        return;
    shadow_width(root->left, hd - 1);
    mx = max(mx, hd);
    mn = min(mn, hd);
    shadow_width(root->right, hd + 1);
}

vector<vector<int>> verticalorder(Node *&root)
{
    queue<Pair> q;
    vector<vector<int>> v;
    if (root == NULL)
        return v;

    shadow_width(root, 0);
    int width = mx - mn + 1;
    v.resize(width);
    q.push({root, abs(mn)});

    while (q.size() > 0)
    {
        Pair p = q.front();
        q.pop();

        Node *temp = p.node;
        v[p.hd].push_back(temp->data);

        if (temp->left != NULL)
        {
            q.push({temp->left, p.hd - 1});
        }

        if (temp->right != NULL)
        {
            q.push({temp->right, p.hd + 1});
        }
    }
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

    // <----- VERTICAL ORDER TRAVERSAL (VERSION 3) (USE OF SHADOW WIDTH)----->
    // ALL THE NODES IN EVERY VECTOR ARE SORTED LEVELWISE
    // TIME COMPLEXITY :- O(N);

    vector<vector<int>> v = verticalorder(root);

    for (auto it : v)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }

        cout << endl;
    }
}
