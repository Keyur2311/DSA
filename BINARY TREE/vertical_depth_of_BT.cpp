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

set<int> st;

// Kind of inorder
void horizontalDis(Node *&root, int hd)
{
    if (root != NULL)
    {
        horizontalDis(root->left, hd - 1);
        st.insert(hd);
        horizontalDis(root->right, hd + 1);
    }
}

int verticalWidth(Node *&root)
{
    st.clear();
    horizontalDis(root, 0);

    return (int)st.size();
}
int main()
{

    struct Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    cout << verticalWidth(root1) << endl;
}

