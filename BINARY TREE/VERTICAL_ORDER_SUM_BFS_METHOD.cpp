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

vector<int> verticalOrderSum(Node *&root)
{
    if (root == NULL)
    {
        vector<int> ans;
        return ans;
    }

    shadow_width(root, 0);
    int width = mx - mn + 1;
    vector<int> ans(width, 0);

    queue<Pair> q;

    q.push(Pair(root, abs(mn)));

    while (!q.empty())
    {
        Pair p = q.front();
        q.pop();

        Node *temp = p.node;
        ans[p.hd] += (temp->data);

        if (temp->left)
        {
            q.push(Pair(temp->left, p.hd - 1));
        }
        if (temp->right)
        {
            q.push(Pair(temp->right, p.hd + 1));
        }
    }

    return ans;
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

    // <----- VERTICAL ORDER SUM (USING BFS) ----->
    // TIME COMPLEXITY :-  O(N)
    // SPACE COMPLEXITY :- O(N)

    vector<int> ans = verticalOrderSum(root);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}


