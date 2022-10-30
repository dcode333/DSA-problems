#include <bits/stdc++.h>
using namespace std;

// Pend

void possiblePaths(int n, int arr[][5], int i, int j)
{
    if ((i == n - 1) && (j == n - 1))
        return;

    if (i >= n || j >= n || arr[i][j] == 0)
        return;

    possiblePaths(n, arr, i + 1, j);
    possiblePaths(n, arr, i, j + 1);

    cout << i << j << endl;
}

int main()
{
    // int a[5][5] = {{1, 0, 1, 0, 1},
    //                {1, 1, 1, 1, 1},
    //                {0, 1, 0, 1, 0},
    //                {1, 0, 0, 1, 1},
    //                {1, 1, 1, 0, 1}};

    int a[5][5] = {{1, 0, 0, 0, 0},
                   {1, 1, 1, 1, 0},
                   {0, 0, 0, 1, 0},
                   {0, 0, 0, 1, 1},
                   {0, 0, 0, 0, 1}};

    possiblePaths(3, a, 0, 0);

    return 0;
}
