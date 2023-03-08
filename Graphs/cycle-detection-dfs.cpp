#include <bits/stdc++.h>
using namespace std;
/*Intution:
- maintain a visited
- do a dfs
- if any child is visited and it's parent is not equal to current node there is cycle
 */

bool isCycle(vector<vector<int>> graph, int vis[], pair<int, int> node) // 0(N + 2E)
{

    vis[node.first] = 1;
    bool res;
    for (auto i : graph[node.first])
    {
        if (!vis[i])
        {
            res = isCycle(graph, vis, {i, node.first});
            if (res)
                return res;
        }
        else if (node.second != i)
            return true;
    }

    return false;
}

int main()
{

    vector<vector<int>> grph = {{3, 2}, {3, 2}, {0, 1, 4}, {0, 1}, {2}};
    int vis[grph.size() + 1] = {0};

    cout << isCycle(grph, vis, {0, -1});

    return 0;
}
