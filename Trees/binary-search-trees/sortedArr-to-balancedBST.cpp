#include <bits/stdc++.h>
using namespace std;
// Red–black tree
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

// original sol
node *buildBalancedBST(vector<int> a, int start, int end)
{
    if (end - start == 0) // if start and end had three elems in b/w
        return new node(a[start]);
    if (end - start < 0) // if start and end had two elems in b/w
        return nullptr;

    int middle = (start + end) / 2; 
    node *root = new node(a[middle]);  //balancing 
    root->left = buildBalancedBST(a, start, middle - 1);
    root->right = buildBalancedBST(a, middle + 1, end);

    return root;
}

int main()
{
    vector<int> a = {10, 20, 30, 40, 50};
    node *root = buildBalancedBST(a, 0, a.size() - 1);
    preOrderTreversal(root);

    return 0;
}
