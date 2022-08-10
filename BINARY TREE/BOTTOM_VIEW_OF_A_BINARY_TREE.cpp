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
    Node *node = NULL;
    int hd = 0;

    Pair(Node *node, int hd)
    {
        this->node = node;
        this->hd = hd;
    }
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

vector<int> bottomView(Node *&root)
{
    queue<Pair> q;
    vector<int> v;
    if (root == NULL)
        return v;

    shadow_width(root, 0);
    int width = mx - mn + 1;
    v.resize(width);
    q.push(Pair(root, abs(mn)));

    while (q.size() > 0)
    {
        Pair p = q.front();
        q.pop();

        Node *temp = p.node;
        v[p.hd] = temp->data;

        if (temp->left != NULL)
        {
            q.push(Pair(temp->left, p.hd - 1));
        }

        if (temp->right != NULL)
        {
            q.push(Pair(temp->right, p.hd + 1));
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
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    // <----- BOTTOM VIEW OF A BINARY TREE ----->

    // TIME  COMPLEXITY :- O(N)
    // SPACE COMPLEXITY :- O(N)

    /* NOTE-: IF YOU DON'T WANT TO USE SHADOW WIDTH THEN STORE  THE ANS IN MAP
              SO THAT NEGATIVE HORIZONTAL LEVAL WILL BE TAKEN CARE OF.
    */

    vector<int> v = bottomView(root);

    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}
