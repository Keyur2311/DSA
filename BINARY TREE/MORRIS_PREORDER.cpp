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

Node *getRightMostNode(Node *&leftNode, Node *&curr)
{
    while (leftNode->right != NULL && leftNode->right != curr)
    {
        leftNode = leftNode->right;
    }

    return leftNode;
}

vector<int> Morris_Preorder(Node *&root)
{
    Node *curr = root;
    vector<int> ans;
    while (curr)
    {
        Node *leftNode = curr->left;
        if (leftNode == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *rightMostNode = getRightMostNode(leftNode, curr);

            if (rightMostNode->right == NULL) // create thread
            {
                ans.push_back(curr->data);
                rightMostNode->right = curr;
                curr = curr->left;
            }
            else // break therad
            {
                rightMostNode->right = NULL;
                curr = curr->right;
            }
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

    //                  MORRIS PREORDER TRAVERSAL
    // SPACE COMPLEXITY = O(1) // Biggest advantage of Morris
    // TIME COMPLEXITY  = O(3N) == O(N) // Every Node is visited 3 or 4 times on an average

    vector<int> Morris = Morris_Preorder(root);

    for (auto it : Morris)
    {
        cout << it << " ";
    }
    cout << endl;
}

