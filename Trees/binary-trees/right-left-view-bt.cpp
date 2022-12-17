#include <bits/stdc++.h>
using namespace std;
/*
Algo:
=> traverse level orderwise
=> in Q before every null every elem will be right view node
=> in Q after every null every elem will be left view node
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

void rightView(node *&root)
{
    if (root == nullptr)
        return;

    queue<node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        node *current = q.front();
        q.pop();
        if (q.front() == nullptr)
            cout << current->val << " ";
        if (current == nullptr)
        {
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
}

void leftView(node *&root)
{

    if (root == nullptr)
        return;

    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    cout << q.front()->val << " ";

    while (!q.empty())
    {
        node *current = q.front();
        q.pop();

        if (current == nullptr)
        {
            if (!q.empty())
            {
                cout << q.front()->val << " ";
                q.push(nullptr);
            }
        }

        else
        {
            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
    }
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
    rightView(root);
    cout << endl;
    leftView(root);

    return 0;
}
