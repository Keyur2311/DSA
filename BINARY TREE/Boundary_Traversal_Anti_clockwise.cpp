#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>
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

vector<int> ans;

bool isLeaf(Node *&node)
{
    return !node->left && !node->right;
}

void addLeftBoundary(Node *&root)
{
    Node *curr = root->left;

    while (curr)
    {
        if (!isLeaf(curr))
            ans.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addLeafNodes(Node *&root)
{
    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if (root->left)
        addLeafNodes(root->left);
    if (root->right)
        addLeafNodes(root->right);
}

void addRightBoundary(Node *&root)
{
    Node *curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (!isLeaf(curr))
            temp.push_back(curr->data);

        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    for (int i = int(temp.size() - 1); i >= 0; i--)
    {
        ans.push_back(temp[i]);
    }
}

void BoundaryTraversalAntiClockWise(Node *&root)
{

    if (!root)
        return;

    if (!isLeaf(root))
        ans.push_back(root->data);

    addLeftBoundary(root);
    addLeafNodes(root);
    addRightBoundary(root);
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

    BoundaryTraversalAntiClockWise(root);

    cout<<"<-----  BOUNDARY TRAVERSAL (ANTI CLOCKWISE VERSION) ----->" <<endl;
    cout<<endl;
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    // cout << "\n\n"
    //      << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " seconds.\n";
}
