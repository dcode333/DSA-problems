#include <bits/stdc++.h>
using namespace std;

//tree on reg

int possiblePaths(int n, int i, int j)
{
    if ((i == n - 1) && (j == n - 1))
        return 1;
    if (i >= n || j >= n)
        return 0;

    return possiblePaths(n, i + 1, j) + possiblePaths(n, i, j + 1);
}

int main()
{
    cout << possiblePaths(3, 0, 0);
    return 0;
}
