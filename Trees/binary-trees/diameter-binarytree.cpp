#include <bits/stdc++.h>
using namespace std;
/*Algo
=> max(left,right)+1 will return the max of (left or right ) to left and right calls
=> max(mx,left+right) will give the maximum path from all nodes that exist in the tree
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

int diameter(node *&root, int &mx)
{
    if (root == nullptr)
        return 0;

    int left = diameter(root->left, mx);
    int right = diameter(root->right, mx);
    mx = max(mx, left + right);
    return max(left, right) + 1;
}

int main()
{
    node *root = new node(4);
    root->right = new node(6);
    root->left = new node(9);
    root->left->left = new node(5);
    root->right->left = new node(5);
    root->right->left->left = new node(7);
    int mx = INT_MIN;
    diameter(root, mx);
    cout << mx;

    return 0;
}
