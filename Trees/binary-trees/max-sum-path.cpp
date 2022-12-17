#include <bits/stdc++.h>
using namespace std;
//hard
/*Algo:
=> compute max from 0 and leftSubTree
=> compute max from 0 and rightSubTree
=> max = max of left and right and root 
(if we say root is -ve then max was already calculated from left or right subTrees) 
=> ret root + max of left and right
(max is returned from left and right subtrees to compute max path to be given to left or rigt)
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

int maxSumPathFromRoot(node *&root, int sum)
{
    if (root == nullptr)
        return sum;

    int left = maxSumPathFromRoot(root->left, sum + root->val);
    int right = maxSumPathFromRoot(root->right, sum + root->val);

    return max(left, right);
}

int maxSumPath(node *&root, int &ans)
{
    if (root == nullptr)
        return 0;

    int left = max(0, maxSumPath(root->left, ans));
    int right = max(0, maxSumPath(root->right, ans));
    ans = max(ans, root->val + left + right);
    return root->val + max(left, right);
}

int main()
{
    node *root = new node(1);
    root->left = new node(-12);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(-6);
    root->right->left = new node(5);
    int maxSum = INT_MIN;
    maxSumPath(root, maxSum);
    cout << maxSum;

    return 0;
}
