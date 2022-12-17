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

int noOfNodes(node *&root)
{
    if (root == nullptr)
        return 0;

    return noOfNodes(root->left) + noOfNodes(root->right) + 1;
}

int sumOfNodes(node *&root)
{
    if (root == nullptr)
        return 0;

    return sumOfNodes(root->left) + sumOfNodes(root->right) + root->val;
}

int main()
{

    node *root = new node(4);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(9);
    root->right->left = new node(5);
    root->right->right = new node(8);
    cout << sumOfNodes(root);

    return 0;
}
