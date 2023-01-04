#include <bits/stdc++.h>
using namespace std;

/*Algo:
=>traverse to the leaf (if root is null return a subTree with 0 size,min,max)
=>if the root is greater than max val of left subtree &
  smaller than min val of right subtree (left and right are bsts)
  return subtree of size
                        left+right,
                        min=min of root and left,
                        max=max of root and right
=>if not return size=max of left and right, min set to a min and max set to max
 so it will always remains a non bst
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

struct valid
{
    int size;
    int min;
    int max;
};

valid largestBSTInBT(node *root)
{
    if (!root)
        return {0, INT_MAX, INT_MIN};

    valid left = largestBSTInBT(root->left);
    valid right = largestBSTInBT(root->right);

    if (root->val > left.max && root->val < right.min)
        // here the min is not needed for left subTree but as we are returning
        // single struct for left and right subtrees so min will be used for getting
        // min of right subtree same goes for (max of right)
        return {
            left.size + right.size + 1, min(left.min, root->val), max(right.max, root->val)};

    return {max(left.size, right.size), INT_MIN, INT_MAX};
}

int main()
{
    node *root = new node(4);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->left->right->right = new node(5);
    cout << largestBSTInBT(root).size;

    return 0;
}
