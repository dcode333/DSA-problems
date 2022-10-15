#include <bits/stdc++.h>
using namespace std;
// pending vid  8.6

int main()
{
    int arr[5] = {2, 4, -6, 7, -4};
    int len = sizeof(arr) / sizeof(arr[0]);

    int summer = 0;
    int MaxSum = INT_MIN;

    //    0(n) approach
    for (int i = 0; i < len; i++)
    {
        summer += arr[i];
        if (summer < 0)
            summer = 0;
        MaxSum = max(MaxSum, summer);
        // cout << summer << endl;
    }

    return 0;
}