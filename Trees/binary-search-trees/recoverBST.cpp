#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

/*Algo
=>traverse in inorder manner because then it will traverse as sorted
=>compare if root is smaller than prev (as two nodes swapped => 2 cases to handle)
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

void inOrderTreversal(node *&root)
{
    if (root == nullptr)
        return;

    inOrderTreversal(root->left);
    cout << root->val << " ";
    inOrderTreversal(root->right);
}

struct ptrs
{
    node *v1 = nullptr;
    node *v2 = nullptr;
    node *v3 = nullptr;
    node *prev = nullptr;
};

void recoverBST(node *&root, ptrs &p)
{
    if (root == nullptr)
        return;

    recoverBST(root->left, p);
    if (p.prev && root->val < p.prev->val)
    {

        if (p.v1)
            p.v3 = root;
        else
        {
            p.v1 = p.prev;
            p.v2 = root;
        }
    }

    p.prev = root; // root is passed after inOrder/Sorted traversal starts

    recoverBST(root->right, p);
}

int main()
{
    node *root = new node(4);
    root->left = new node(6);
    root->right = new node(5);
    root->left->left = new node(2);
    root->right->left = new node(3);
    ptrs p;
    recoverBST(root, p);
    if (!p.v3)
        swap(p.v1->val, p.v2->val);
    else
        swap(p.v1->val, p.v3->val);

    inOrderTreversal(root);

    return 0;
}
