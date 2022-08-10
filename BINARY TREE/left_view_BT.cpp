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

vector<int> leftViewBT(Node *root)
{
    queue<Node *> q;
    q.push(root);
    vector<int> leftView;
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (i == 0)
            {
                leftView.push_back(temp->data);
            }
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    return leftView;
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

    // <----- LEFT VIEW OF A BINARY TREE ----->

    // TIME COMPLEXITY :-  O(N)
    // SPACE COMPLEXITY :- O(1)  (VECTOR FOR STORING THE ANS IS NOT CONSIDERED)

    vector<int> v = leftViewBT(root);
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}
