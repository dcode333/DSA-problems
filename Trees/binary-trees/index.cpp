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

void preOrderTreversal(node *&root)
{
    if (root == nullptr)
        return;

    cout << root->val << " ";
    preOrderTreversal(root->left);
    preOrderTreversal(root->right);
}

int main()
{
    node *root = new node(4);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(9);
    root->right->left = new node(5);
    cout << preOrderTreversal(root);

    return 0;
}
