#include <bits/stdc++.h>
using namespace std;
/*Algo:


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

// original solution
int getPathDist(node *root, int target, int res)
{
    if (root == nullptr)
        return 0;

    if (root->val == target)
        return res;

    int left = getPathDist(root->left, target, res + 1);
    // if (left)  //Optimization
    //     return left;
    int right = getPathDist(root->right, target, res + 1);

    return right + left;
}

node *LCA(node *&root, int n1, int n2)
{
    if (root == nullptr)
        return nullptr;

    if (root->val == n1 || root->val == n2)
        return root;

    node *left = LCA(root->left, n1, n2);
    node *right = LCA(root->right, n1, n2);

    if (left && right)
        return root;

    if (left)
        return left;

    return right;
}

int shortestDistanceTwoNodes(node *&root, int n1, int n2)
{

    node *lca = LCA(root, n1, n2);

    return getPathDist(lca, n1, 0) + getPathDist(lca, n2, 0);
}

void distK(node *&root, node *traverser, int target, int k)
{

    if (traverser == nullptr)
        return;

    int dist = shortestDistanceTwoNodes(root, target, traverser->val);
    if (dist == k)
        cout << target << " from " << traverser->val << endl;

    distK(root, traverser->left, target, k);
    distK(root, traverser->right, target, k);
}

int main()
{

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(5);
    root->right->left = new node(8);
    distK(root, root, 2, 1);

    return 0;
}