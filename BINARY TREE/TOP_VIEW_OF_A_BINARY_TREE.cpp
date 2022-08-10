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

int mn = INT_MAX, mx = INT_MIN;
void shadow_Width(Node *&root, int hd)
{
    if (root == NULL)
        return;

    shadow_Width(root->left, hd - 1);
    mn = min(mn, hd);
    mx = max(mx, hd);
    shadow_Width(root->right, hd + 1);
}

vector<int> topView(Node *&root)
{
    vector<int> x;
    if (root == NULL)
    {
        return x;
    }

    shadow_Width(root, 0);
    int width = mx - mn + 1;

    vector<int> v(width);
    for (int i = 0; i < width; i++)
        v[i] = INT_MAX;

    queue<Pair> q;
    q.push(Pair(root, abs(mn)));
    while (q.size() > 0)
    {
        Pair p = q.front();
        q.pop();
        Node *temp = p.node;
        if (v[p.hd] == INT_MAX)
        {
            v[p.hd] = temp->data;
        }

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
    root->right->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right->right = new Node(7);

    // <----- TOP VIEW OF A BINARY TREE ----->
    // TIME COMPLEXITY :- O(N)  (LEVEL ORDER TRAVERSAL + SHADOW_WIDTH)
    // AUXILIARY SPACE :- O(N) (for queue)

    vector<int> v = topView(root);

    for (auto it : v)
    {
        cout << it << " ";
    }
}

