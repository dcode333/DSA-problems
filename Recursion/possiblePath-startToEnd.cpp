#include <bits/stdc++.h>
using namespace std;

//Tree on reg

int possiblePaths(int s, int e)
{
    if (s == e)
        return 1;
    if (s > e)
        return 0;

    int count = 0;
    for (int i = 1; i <= 6; i++)
        count += possiblePaths(s + i, e);

    return count;
}

int main()
{
    cout << possiblePaths(0, 3);


    return 0;
}
