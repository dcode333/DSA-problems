#include <bits/stdc++.h>
using namespace std;
/* Store
   1) Adj Matrix
   2) Adj List
   space: 0(2*edges)
*/

// SC : N + N + N = 0(N)
// TC : 0(N + 2E)
int dfs(vector<vector<int>> graph, vector<vector<int>> visited, int row, int col, int dist)
{
    if (row < 0 || row >= graph[0].size() || col < 0 || col >= graph.size() || visited[row][col])
        return INT_MAX;

    visited[row][col] = 1;

    if (graph[row][col])
        return dist;

    int left = dfs(graph, visited, row - 1, col, dist + 1);
    int top = dfs(graph, visited, row, col - 1, dist + 1);
    int right = dfs(graph, visited, row + 1, col, dist + 1);
    int bottom = dfs(graph, visited, row, col + 1, dist + 1);

    return min(left, min(top, min(right, bottom)));
}

int main()
{

    vector<vector<int>> grid{
        {0, 0, 0},
        {0, 1, 1},
        {0, 0, 1}};

    vector<vector<int>> vis{
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};

    cout << dfs(grid, vis, 0, 0, 0);
    return 0;
}
