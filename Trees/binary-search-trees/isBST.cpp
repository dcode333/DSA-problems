#include <bits/stdc++.h>
using namespace std;
/*Algo:
=> check if your root is smaller than max and larger than min (should lie b/w min--max)
=> recurse for left subtree as max=root and min=min
=> recurse for right subtree as max=max and min=root
*/

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

bool isBST(node *&root, node *min, node *max)
{
    if (root == nullptr)
        return true;

    if (min && root->val <= min->val)
        return false;
    if (max && root->val >= max->val)
        return false;

    bool left = isBST(root->left, min, root);
    bool right = isBST(root->right, root, max);

    return left && right;
}

int main()
{
    node *root = new node(4);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(2);
    root->right->left = new node(1);

    cout << isBST(root, nullptr, nullptr);

    return 0;
}
