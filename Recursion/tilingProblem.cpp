#include <bits/stdc++.h>
using namespace std;
// algo : self made with a pattern detection

int tilingWays(int n, int counter)  
{
    if (counter == n)
        return (2 * n + (counter - 2));

    return tilingWays(n, counter + 1);
}

int main()
{
    // int n = 5;
    // int counter = 0;
    // for (int i = 2; i < n; i++)
    //     counter++;
    // cout << (2 * n + counter) << " ways";

    cout << tilingWays(4, 2);

    return 0;
}
