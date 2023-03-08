#include <bits/stdc++.h>
using namespace std;
/* Store
   1) Adj Matrix
   2) Adj List
   space: 0(2*edges)

   use-case:
   case of finding the shortest path in any form,
   here it was nearest one i,e minimum distance
   where one is located, you use BFS.
*/

void bfs(vector<vector<int>> graph) // 0(N + 2E)
{
    int vis[graph.size() + 1] = {0};
    queue<int> que;
    que.push(0);
    vis[0] = 1;

    while (!que.empty())
    {
        int node = que.front();
        que.pop();
        cout << node << " ";
        for (int j = 0; j < graph[node].size(); j++)
        {
            if (!vis[graph[node][j]])
            {
                vis[graph[node][j]] = 1;
                que.push(graph[node][j]);
            }
        }
    }
}

int main()
{

    vector<vector<int>> grph = {{3, 2}, {3, 2}, {0, 1, 4}, {0, 1}, {2}};

    bfs(grph);

    return 0;
}
