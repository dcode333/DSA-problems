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

int treeHeight2(node *&root)
{

    queue<node *> q;
    int level = 0;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        node *current = q.front();
        q.pop();
        if (current == nullptr)
        {
            level++;
            if (!q.empty())
                q.push(nullptr);
        }

        else
        {
            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
    }

    return level;
}

int treeHeight(node *&root)
{
    if (root == nullptr)
        return 0;

    int leftDepth = treeHeight(root->left);
    int rightDepth = treeHeight(root->right);

    return max(leftDepth, rightDepth) + 1;
}

int main()
{

    node *root = new node(4);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(9);
    root->left->right = new node(5);
    root->right->left = new node(9);
    root->right->right = new node(5);
    cout << treeHeight(root);

    return 0;
}
