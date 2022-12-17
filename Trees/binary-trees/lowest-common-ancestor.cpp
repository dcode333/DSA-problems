#include <bits/stdc++.h>
using namespace std;
/*Algo:
LCA:
=> declare two vectors to store pathq and path2
=> declare a getPath and push the root in vector
=> find target in left and right sub trees
=> if root=null pop the root
=> after getting both paths chk for last equal nodes

LCA2:
=> if root = n1 or n2 return root
=> check in left and right sub trees and assign both to variables
=> if both are not null then root is the lca
=> if right is not null keep returning right
=> if left is not null keep returning left

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

//&res to manipulate the passed vector
bool getPath(node *root, int target, vector<int> &res)
{
    if (root == nullptr)
        return false;

    res.push_back(root->val);

    if (root->val == target)
        return true;

    if (getPath(root->left, target, res) || getPath(root->right, target, res))
        return true;

    res.pop_back();
    return false;
}

int LCA(node *&root, int n1, int n2)
{
    vector<int> p1, p2;

    if (!getPath(root, n2, p2) || !getPath(root, n1, p1))
        return -1;

    for (int i = 0; i < p1.size() && i < p2.size(); i++)
        if (p1[i] != p2[i])
            return p1[i - 1];
}

node *LCA2(node *&root, int n1, int n2)
{
    if (root == nullptr)
        return nullptr;

    if (root->val == n1 || root->val == n2)
        return root;

    node *left = LCA2(root->left, n1, n2);
    node *right = LCA2(root->right, n1, n2);

    if (left && right)
        return root;

    if (left)
        return left;

    return right;
}

int main()
{

    node *root = new node(4);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(9);
    root->right->left = new node(5);
    root->right->right = new node(7);
    cout << LCA2(root, 7, 5)->val;

    return 0;
}