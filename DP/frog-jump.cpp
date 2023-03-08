#include <bits/stdc++.h>
using namespace std;

int frogJumps(int n, vector<int> heights, int diffStorer, vector<int> &dp)
{

    if (n == 0)
        return diffStorer;
    // if (dp[n] != -1)
    //     return dp[n];

    int one = frogJumps(n - 1, heights, diffStorer + abs(heights[n] - heights[n - 1]), dp);
    int two = INT_MAX;
    if (n > 1) 
        two = frogJumps(n - 2, heights, diffStorer + abs(heights[n] - heights[n - 2]), dp);

    dp[n] = min(one, two);

    return dp[n];
}

int main()
{
    vector<int> heights = {30, 10, 60, 10};
    vector<int> dp(heights.size() + 1, -1);
    cout << frogJumps(heights.size() - 1, heights, 0, dp);
    cout << endl;

    for (int i = 0; i < dp.size(); i++)
        cout << dp[i] << " ";

    return 0;
}

// int frogJumps(int n, vector<int> heights, int diffStorer, vector<int> &dp)
// {
//     // if (dp[n] != -1)
//     // {
//     //     cout << dp[n] << " " << n << " ";
//     //     return dp[n];
//     // }
//     if (n >= heights.size())
//         return INT_MAX;

//     if (n == heights.size() - 1)
//         return diffStorer;

//     int one = frogJumps(n + 1, heights, diffStorer + abs(heights[n] - heights[n + 1]), dp);
//     int two = frogJumps(n + 2, heights, diffStorer + abs(heights[n] - heights[n + 2]), dp);

//     return dp[n] = min(one, two);
// }
