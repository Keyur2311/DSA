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

vector<vector<int>> diagonalOrder(Node *&root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }

    queue<Node *> q;
    q.push(root);

    while (q.size() > 0)
    {
        int n = q.size();
        vector<int> v;

        while (n--)
        {
            Node *node = q.front();
            q.pop();
            while (node != NULL)
            {
                v.push_back(node->data);
                if (node->right != NULL)
                {
                    q.push(node->right);
                }
                node = node->left;
            }
        }
        ans.push_back(v);
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

    // <----- DIAGONAL ORDER OF A BINARY TREE (ANTICLOCKWISE)----->
    //  TIME COMPLEXITY :- O(N)
    //  AUXILIARY SPACE :- O(N) (for queue)

    vector<vector<int>> v = diagonalOrder(root);

    for (auto it : v)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

