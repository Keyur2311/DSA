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

int ans = 0;
int tiltOfBT(Node *&root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = tiltOfBT(root->left);
    int right = tiltOfBT(root->right);

    ans += abs(left - right); // making change in ans

    return left + right + root->data;
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

    // <-----  TILT A BINARY TREE  ------>
    // (USING TRAVEL AND CHANGE TECHNIQUE) -> WE ARE RETURNING SUM IN RECURSION BUT WE ARE CHANGING ANS VARIABLE

    // TIME COMPLEXITY :- O(N)
    // SPACE COMPLEXITY :- O(1) (FOR CALL STACK -> O(N))

    int x = tiltOfBT(root);

    cout << ans << endl;
}

