#include <bits/stdc++.h>
using namespace std;
// see tree in z-docs

class node
{
public:
    int val;
    node *left;
    node *right;

    node(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};
int treeHeight(node *&root)
{
    if (root == nullptr)
        return 0;

    int leftDepth = treeHeight(root->left);
    int rightDepth = treeHeight(root->right);

    return max(leftDepth, rightDepth) + 1;
}

// O(n^2)
bool isBalanced(node *&root)
{
    if (root == nullptr)
        return true;

    int leftTree = treeHeight(root->left); // O(n)
    int rightTree = treeHeight(root->right);

    bool rblnce = isBalanced(root->left);
    bool lblnce = isBalanced(root->right);

    if (abs(leftTree - rightTree) > 1)
        return false;
    if (rblnce && lblnce)
        return true;
}

// O(n)
bool isBalnced(node *&root, int *height)
{

    if (root == nullptr)
        return true;
    int lh = 0, rh = 0;

    bool rblnce = isBalnced(root->left, &lh);
    bool lblnce = isBalnced(root->right, &rh);

    *height = max(lh, rh) + 1;
    if (abs(lh - rh) > 1)
        return false;
    if (rblnce && lblnce)
        return true;
}

int main()
{

    node *root = new node(4);
    root->left = new node(3);
    // root->right = new node(6);
    root->left->left = new node(9);
    root->left->right = new node(5);
    // root->right->left = new node(9);
    // root->right->right = new node(5);
    int h = 0;
    cout << isBalnced(root, &h);

    return 0;
}
