
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
int camera = 0;

/*
1. If you need a camera return -1
2. If you have a camera return 0
3. If you are already covered return 1;
*/
int MinCamerasBT(Node *&root)
{
    if (root == NULL)
        return 1; // If there don't exist a node means it is already covered

    int lchild = MinCamerasBT(root->left);
    int rchild = MinCamerasBT(root->right);

    if (lchild == -1 || rchild == -1) // If one of Node's child needs camera means Node must have a camera
    {
        camera++;
        return 0; // Node have a camera
    }

    // Now If anyone of node's child don't need a camera then there are two possibillities
    // 1. child already has camera
    // 2. child is already covered

    if (lchild == 0 || rchild == 0)
    {
        return 1; // one of node's child have a camera so Node itself don't need a camera
    }

    // else Node must need a camera

    return -1;
}
int minCamera(Node *&root)
{

    if (MinCamerasBT(root) == -1) // if the root of the tree needs a camera then root itself must have a camera
    {
        camera++;
    }

    return camera;
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

    // <----- CAMERAS IN A BINARY TREE (LEETCODE)  ------>

    // TIME COMPLEXITY :- O(N)
    // SPACE COMPLEXITY :- O(1)

    cout << minCamera(root) << endl;
}
