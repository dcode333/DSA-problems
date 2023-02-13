#include <bits/stdc++.h>
using namespace std;

void sudokuSolver(vector<vector<int>> &sudoku, int r, int c)
{
    if (c >= sudoku[0].size() || r >= sudoku.size())
        return;
    cout << r << c << endl;
    sudoku[r][c] = r + c;
    sudokuSolver(sudoku, r + 1, c);
    sudokuSolver(sudoku, r, c + 1);
}

int main()
{
    vector<vector<int>> sudoku = {

        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},    
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}

    };

    sudokuSolver(sudoku, 0, 0);
    for (int i = 0; i < sudoku.size(); i++)
    {
        for (int j = 0; j < sudoku[i].size(); j++)
            cout << sudoku[i][j] << " ";

        cout << endl;
    }

    return 0;
}
