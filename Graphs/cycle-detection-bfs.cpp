#include <bits/stdc++.h>
using namespace std;
/*Intution:
- maintain a visited 
- do a bfs 
- if any child is visited its parent is not the ith element then there is a cycle
 */

bool isCycle(vector<vector<int>> graph) // 0(N + 2E)
{
    queue<pair<int, int>> que;
    int visited[graph.size()] = {0};

    que.push({0, -1});

    while (!que.empty())
    {
        int idx = que.front().first;
        int parent = que.front().second;
        visited[idx] = 1;
        que.pop();

        for (int i = 0; i < graph[idx].size(); i++)
        {
            if (!visited[graph[idx][i]])
            {
                que.push({graph[idx][i], idx});
                visited[graph[idx][i]] = 1;
            }
            else if (visited[graph[idx][i]] != parent)
                return true;
        }
    }

    return false;
}

int main()
{

    vector<vector<int>> grph = {{3, 2}, {3, 2}, {0, 1, 4}, {0, 1}, {2}};

    cout << isCycle(grph);

    return 0;
}
