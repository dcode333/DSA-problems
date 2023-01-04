#include <bits/stdc++.h>
using namespace std;
/*delete bst:
=> node to be deleted has both childs:
      Replace its value with its inorder successor's value and recurse to
      the right to delete its inOrder's successor
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

void insertBSTOrg(node *&root, int data)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->val > data)
    {
        node *newNode = new node(data);
        root->left = newNode;
        return;
    }

    if (root->right == nullptr && root->val < data)
    {
        node *newNode = new node(data);
        root->right = newNode;
        return;
    }

    if (root->val > data)
        insertBSTOrg(root->left, data);
    else if (root->val < data)
        insertBSTOrg(root->right, data);
}

node *insertBST(node *root, int data)
{
    if (root == nullptr)
        return new node(data);

    if (root->val > data)
        root->left = insertBST(root->left, data);
    else if (root->val < data)
        root->right = insertBST(root->right, data);

    return root;
}

void inOrderTreversal(node *&root)
{
    if (root == nullptr)
        return;

    inOrderTreversal(root->left);
    cout << root->val << " ";
    inOrderTreversal(root->right);
}

int searchBST(node *&root, int target)
{
    if (root == nullptr)
        return -1;

    if (root->val > target)
        return searchBST(root->left, target);

    else if (root->val < target)
        return searchBST(root->right, target);

    else
        return root->val;
}

node *inOrderSuccessor(node *root)
{
    node *temp = root;
    while (temp && temp->left)
        temp = temp->left;

    return temp;
}
node *deleteBST(node *&root, int target)
{
    if (target < root->val)
        root->left = deleteBST(root->left, target);
    else if (target > root->val)
        root->right = deleteBST(root->right, target);
    else
    {
        node *temp = root;
        if (!root->left)
        {
            free(root);
            return root->right;
        }
        if (!root->right)
        {
            free(root);
            return root->left;
        }
        if (root->right && root->left)
        {
            node *inOrSuc = inOrderSuccessor(root->right);
            root->val = inOrSuc->val;
            root->right = deleteBST(root->right, inOrSuc->val);
        }
    }
}

int main()
{
    // vector<int> v = {2, 3, 4, 6, 7, 8, 9};
    node *root = insertBST(nullptr, 5);

    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 6);
    deleteBST(root, 5);
    inOrderTreversal(root);
    return 0;
}
