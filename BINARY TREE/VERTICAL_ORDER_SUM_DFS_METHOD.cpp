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

void shadow_width(Node *root, int hd)
{
    if (root == NULL)
        return;
    shadow_width(root->left, hd - 1);
    mn = min(mn, hd);
    mx = max(mx, hd);
    shadow_width(root->right, hd + 1);
}

void vSum(Node *root, int hd, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    v[hd] += (root->data);
    vSum(root->left, hd - 1, v);
    vSum(root->right, hd + 1, v);
}
vector<int> verticalOrderSum(Node *root)
{
    shadow_width(root, 0);
    int width = mx - mn + 1;
    vector<int> v(width, 0);

    vSum(root, abs(mn), v);

    return v;
}

int main()
{

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // <----- VERTICAL ORDER SUM (USING DFS) ----->
    // TIME COMPLEXITY :-  O(N)
    // SPACE COMPLEXITY :- O(N)

    vector<int> ans = verticalOrderSum(root);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}
