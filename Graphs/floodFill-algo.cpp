#include <bits/stdc++.h>
using namespace std;

/*
no memoization through visited array
 cuz when the color is changed it'll act as a memory
 */


void dfs(vector<vector<int>> graph, int vis[], int node)
{

    if (vis[node])
        return;

    cout << node << " ";

    vis[node] = 1;

    for (int i = 0; i < graph[node].size(); i++)
        dfs(graph, vis, graph[node][i]);
}

void floodFill(vector<vector<int>> &grid, int sr, int sc, int newColor)
{
    if (sr < 0 || sr >= grid[0].size() || sc < 0 || sc >= grid.size() || grid[sr][sc] != newColor)
        return;

    // cout << sr << " " << sc << endl;

    grid[sr][sc]++;

    floodFill(grid, sr - 1, sc, newColor);
    floodFill(grid, sr + 1, sc, newColor);
    floodFill(grid, sr, sc - 1, newColor);
    floodFill(grid, sr, sc + 1, newColor);
}

int main()
{

    vector<vector<int>> grph = {

        {1, 0, 1},
        {1, 0, 0},
        {1, 0, 1},

    };

    floodFill(grph, 0, 0, 1);

    for (int i = 0; i < grph.size(); i++)
    {
        for (int j = 0; j < grph[0].size(); j++)
            cout << grph[i][j] << " ";
        cout << endl;
    }

    return 0;
}
