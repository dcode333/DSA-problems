#include <bits/stdc++.h>
using namespace std;
/*
Algo: (queue)
=> push root and null
=> pop front elem print and push left,right of popped elem
=> if popped = null then push it again at back
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

void levelOrderTrevrsal(node *&root)
{
    queue<node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        node *current = q.front();
        q.pop();
        if (current == nullptr)
        {
            cout << "\n";
            if (!q.empty())
                q.push(current);
        }
        else
        {
            cout << current->val << ' ';
            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
    }
}

void levelOrderSum(node *&root, int k)
{
    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    int num = 0;
    int sum = 0;

    while (!q.empty())
    {
        node *current = q.front();
        q.pop();
        if (current == nullptr)
        {
            num++;
            if (!q.empty())
                q.push(current);
        }
        else
        {
            if (num == k)
                sum += current->val;
            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
    }
    cout << sum;
}



int main()
{

    node *root = new node(4);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(9);
    root->right->left = new node(5);
    root->right->right = new node(8);
    cout << levelOrderSum(root);

    return 0;
}
