#include <bits/stdc++.h>
using namespace std;
/* Store
   1) Adj Matrix
   2) Adj List
   space: 0(2*edges)
*/

// SC : N + N + N = 0(N)
// TC : 0(N + 2E)
void dfs(vector<vector<int>> graph, int vis[], int node)
{

    if (vis[node])
        return;

    cout << node << " ";

    
    vis[node] = 1;

    for (int i = 0; i < graph[node].size(); i++)
        dfs(graph, vis, graph[node][i]);
}

int main()
{

    vector<vector<int>> grph = {{3, 2}, {3, 2}, {0, 1, 4}, {0, 1}, {2}};
    int vis[grph.size() + 1] = {0};

    dfs(grph, vis, 0);

    return 0;
}
