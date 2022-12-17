#include <bits/stdc++.h>
using namespace std;

/*Algo:
=> ret if root , ->right, -> left is null
=> see if left sub tree is null
=> if not recurse for left sub tree
=> store the right sub tree in (temp) -> make right sub tree = left subtree
=> assign tail of right sub tree(prev left sub tree) = temp
=> recurse for right sub tree
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

void flattenBT(node *&root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return;

    if (root->left != nullptr)
    {
        flattenBT(root->left);

        node *temp = root->right;
        root->right = root->left;
        root->left = nullptr;

        node *leftTail = root->right;
        while (leftTail->right != nullptr)
            leftTail = leftTail->right;

        leftTail->right = temp;
    }
    flattenBT(root->right);
}

int main()
{
    node *root = new node(4);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(9);
    root->right->left = new node(5);
    flattenBT(root);
    while (root != nullptr)
    {
        cout << root->val << " ";
        root = root->right;
    }

    return 0;
}
