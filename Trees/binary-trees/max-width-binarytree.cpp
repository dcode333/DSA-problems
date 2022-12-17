#include <bits/stdc++.h>
using namespace std;
/*Algo:
dry run one iteration must
=> Traverse in level order
=> Index of (left most node - right most node) + 1  will give us max width
=> Indexing -> 0 based Indexing is done with (i - Index of left most node) to avoid number overflow
=> all nodes b/w leftmost and rightmost nodes will be counted
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

int maxWidthBT(node *&root)
{
    if (root == nullptr)
        return -1;

    pair<node *, int> p;
    queue<pair<node *, int>> q;
    int maxWidth = 1, last = 0, first = 0;

    q.push({root, 0});
    q.push({nullptr, 0});

    while (!q.empty())
    {
        node *current = q.front().first;
        int currentNodeIndex = q.front().second;
        q.pop();
        if (q.front().first == nullptr)
        {
            last = currentNodeIndex;
            maxWidth = max(maxWidth, last - first + 1);
        }

        if (current == nullptr)
        {
            if (!q.empty())
            {
                first = q.front().second; // also treating as minium index at this level
                cout << first << endl;
                p.first = current;
                q.push(p);
            }
        }
        else
        {
            if (current->left != nullptr)
            {

                p.first = current->left;
                p.second = 2 * (currentNodeIndex - first) + 1;
                q.push(p);
            }
            if (current->right != nullptr)
            {
                p.first = current->right;
                p.second = 2 * (currentNodeIndex - first) + 2;
                q.push(p);
            }
        }
    }

    return maxWidth;
}

int main()
{

    node *root = new node(4);
    root->left = new node(3);
    root->right = new node(6);
    root->left->right = new node(9);
    root->left->left = new node(9);
    root->left->left->left = new node(9);
    root->left->right->left = new node(5);
    root->right->right = new node(5);
    root->right->right->left = new node(5);
    cout << maxWidthBT(root);

    return 0;
}
