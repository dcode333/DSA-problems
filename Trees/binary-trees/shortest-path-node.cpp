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

    return left + right;
}

int main()
{

    return 0;
}
