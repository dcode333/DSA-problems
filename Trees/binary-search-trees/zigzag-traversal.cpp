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

void zigZagTraversal(node *&root)
{
    vector<node *> q;
    q.push_back(nullptr);
    q.push_back(root);
    int reader = q.size() - 1;
    bool traverseDirection = true, hasChildrens = false;

    while (true)
    {
        node *current = q[reader];
        if (current == nullptr)
        {
            if (!hasChildrens)
                break;
            hasChildrens = false;
            traverseDirection = !traverseDirection;
            reader = q.size();
            cout << "\n";
        }
        else
        {
            cout << current->val<<" ";

            if (traverseDirection)
            {
                if (current->left)
                {
                    hasChildrens = true;
                    q.push_back(current->left);
                }
                if (current->right)
                {
                    hasChildrens = true;
                    q.push_back(current->right);
                }
            }
            else
            {
                if (current->right)
                {
                    hasChildrens = true;
                    q.push_back(current->right);
                }
                if (current->left)
                {
                    hasChildrens = true;
                    q.push_back(current->left);
                }
            }
            q[reader] = nullptr;
        }

        reader--;
    }
}

int main()
{
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->left->left = new node(1);
    root->left->right = new node(5);
    root->right->right = new node(7);
    root->right->left = new node(0);
    root->left->left->left = new node(4);
    root->right->right->left = new node(2);
    zigZagTraversal(root);

    return 0;
}
