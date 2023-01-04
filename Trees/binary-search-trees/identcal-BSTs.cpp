#include <bits/stdc++.h>
using namespace std;

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

bool areIdentical(node *&rootA, node *&rootB)
{
    if (!rootA && !rootB)
        return true;

    if (!rootA || !rootB)
        return false;

    if (rootA->val != rootB->val)
        return false;

    bool left = areIdentical(rootA->left, rootB->left);
    bool right = areIdentical(rootA->right, rootB->right);

    return left && right;
}

int main()
{
    node *root = new node(4);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(2);
    root->right->left = new node(1);

    node *root2 = new node(4);
    root2->left = new node(3);
    root2->right = new node(6);
    root2->left->left = new node(2);
    root2->right->left = new node(1);

    cout << areIdentical(root, root2);

    return 0;
}
