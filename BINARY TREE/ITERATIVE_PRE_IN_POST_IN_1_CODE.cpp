
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
class Pair
{
public:
    Node *node;
    int state;
    Pair() {}
    Pair(Node *node, int state)
    {
        this->node = node;
        this->state = state;
    }
};


void iterativePreInPost(Node *root, vector<int> &pre, vector<int> &in, vector<int> &post)
{
    stack<Pair> st;
    st.push(Pair(root, 1));

    while (st.size() > 0)
    {
        Pair p = st.top();

        if (p.state == 1)
        {
            pre.push_back(p.node->data);
            st.top().state++;
            if (p.node->left)
            {
                st.push(Pair(p.node->left, 1));
            }
        }
        else if (p.state == 2)
        {
            in.push_back(p.node->data);
            st.top().state++;
            if (p.node->right)
            {
                st.push(Pair(p.node->right, 1));
            }
        }
        else
        {
            post.push_back(p.node->data);
            st.pop();
        }
    }
}
int main()
{

    // ITERARTIVE PREORDER INORDER AND POSTORDER
    // TIME COMPLEXITY  :- O(N)
    // SPACE COMPLEXITY :- O(N)

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> pre, in, post;
    iterativePreInPost(root, pre, in, post);

    for (auto it : pre)
    {
        cout << it << " ";
    }
    cout << endl;

    for (auto it : in)
    {
        cout << it << " ";
    }
    cout << endl;

    for (auto it : post)
    {
        cout << it << " ";
    }
    cout << endl;
}
