#include <bits/stdc++.h>
using namespace std;
/*
Algo:
-traverse through the grid
-Do a bfs or dfs if there is a 1(land).
-mark all the nodes if visited
-count the no of times you do search for a non-visited 1
*/

void dfs(int row, int col, vector<vector<int>> graph, vector<vector<int>> &visited)
{

    if (visited[row][col])
        return;

    visited[row][col] = 1;

    for (int deli = -1; deli <= 1; deli++)
    {
        for (int delj = -1; delj <= 1; delj++)
        {
            int drow = row + deli;
            int dcol = col + delj;

            if (drow >= 0 && drow < graph[0].size() && dcol >= 0 && dcol < graph.size() && !visited[drow][dcol] && graph[drow][dcol])
                dfs(drow, dcol, graph, visited);
        }
    }
}
void bfs(int row, int col, vector<vector<int>> grph, vector<vector<int>> &visited)
{
    queue<pair<int, int>> que;
    visited[row][col] = 1;
    que.push(make_pair(row, col));
    int n = grph[0].size();
    int m = grph.size();

    while (!que.empty())
    {
        pair<int, int> curr = que.front();
        que.pop();

        for (int deli = -1; deli <= 1; deli++)
        {
            for (int delj = -1; delj <= 1; delj++)
            {
                int drow = curr.first + deli;
                int dcol = curr.second + delj;

                if (drow >= 0 && drow < n && dcol >= 0 && dcol < m && !visited[drow][dcol] && grph[drow][dcol])
                {
                    visited[drow][dcol] = 1;
                    que.push({drow, dcol});
                }
            }
        }
    }
}

int noOfIslands(vector<vector<int>> grph)
{
    int row = grph[0].size();
    int col = grph.size();
    vector<vector<int>> visited(col, vector<int>(row, 0));
    int islands = 0;

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (grph[i][j] && !visited[i][j])
            {

                dfs(i, j, grph, visited);
                // bfs(i, j, grph, visited);
                islands++;
            }
        }
    }

    return islands;
}

int main()
{

    vector<vector<int>> grph = {

        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 0, 1, 1, 1},
        {1, 0, 1, 1, 1},

    };

    cout << noOfIslands(grph);

    return 0;
}
