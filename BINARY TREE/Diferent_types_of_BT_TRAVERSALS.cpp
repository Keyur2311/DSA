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
void printVecofVec(vector<vector<int>> v)
{
    for (auto it : v)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

void recursiveInorder(Node *&root)
{
    if (root == NULL)
        return;
    recursiveInorder(root->left);
    cout << root->data << " ";
    recursiveInorder(root->right);
}

void recursivePreorder(Node *&root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    recursivePreorder(root->left);
    recursivePreorder(root->right);
}

void recursivePostorder(Node *&root)
{
    if (root == NULL)
        return;
    recursivePostorder(root->left);
    recursivePostorder(root->right);
    cout << root->data << " ";
}

void IterativePreorder(Node *&root)
{
    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();

        cout << temp->data << " ";

        if (temp->right != NULL)
        {
            st.push(temp->right);
        }
        if (temp->left != NULL)
        {
            st.push(temp->left);
        }
    }
}

void IterativeInorder(Node *&root)
{
    stack<Node *> st;
    Node *temp = root;

    while (true)
    {
        if (temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            if (st.empty())
                break;

            temp = st.top();
            st.pop();

            cout << temp->data << " ";
            temp = temp->right;
        }
    }
}
void IterativePostorder(Node *&root)
{
    stack<Node *> st;
    stack<int> ans;
    st.push(root);

    while (!st.empty())
    {

        Node *temp = st.top();
        st.pop();

        ans.push(temp->data);

        if (temp->left != NULL)
        {
            st.push(temp->left);
        }
        if (temp->right != NULL)
        {
            st.push(temp->right);
        }
    }

    while (ans.size() > 0)
    {
        cout << ans.top() << " ";
        ans.pop();
    }


}
vector<vector<int>> BFS(Node *&root)
{
    queue<Node *> q;
    q.push(root);

    vector<vector<int>> ans;

    while (!q.empty())
    {
        int n = q.size();
        vector<int> v;
        while (n--)
        {
            Node *temp = q.front();
            q.pop();

            v.push_back(temp->data);
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        ans.push_back(v);
    }
    return ans;
}

vector<vector<int>> ZigZagTraversal(Node *&root)
{
    queue<Node *> q;
    q.push(root);

    vector<vector<int>> ans;
    int ctr = 1;

    while (!q.empty())
    {
        int n = q.size();
        vector<int> v;
        while (n--)
        {
            Node *temp = q.front();
            q.pop();

            v.push_back(temp->data);
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        if (ctr % 2 == 0)
        {
            reverse(v.begin(), v.end());
        }
        ans.push_back(v);
        ctr++;
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

    cout << " <----- RECURSIVE DSF TECHNIQUES ----->" << endl;
    cout << endl;
    cout << "PREORDER :- "
         << " ";
    recursivePreorder(root);
    cout << endl;

    cout << "INORDER :- "
         << " ";
    recursiveInorder(root);
    cout << endl;

    cout << "POSTORDER :- "
         << " ";
    recursivePostorder(root);
    cout << endl;

    cout << endl;

    cout << " <----- ITERATIVE DSF TECHNIQUES ----->" << endl;
    cout << endl;

    cout << "PREORDER :- "
         << " ";
    IterativePreorder(root);
    cout << endl;

    cout << "INORDER :- "
         << " ";
    IterativeInorder(root);
    cout << endl;

    cout << "POSTORDER :- "
         << " ";
    IterativePostorder(root);
    cout << endl;

    cout << endl;
    cout << " <----- BFS TRAVERSAL TECHNIQUES ----->" << endl;
    cout << endl;
    cout << " <----- LEVEL ORDER TRAVERSAL (SIMPLE BFS) ----->" << endl;
    vector<vector<int>> v1 = BFS(root); // level order traversal
    printVecofVec(v1);
    cout << endl;

    cout << " <----- ZIG ZAG TRAVERSAL ----->" << endl;
    vector<vector<int>> v2 = ZigZagTraversal(root);
    printVecofVec(v2);
    cout << endl;

    cout << "\n\n"
         << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " seconds.\n";
}

