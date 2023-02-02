#include <bits/stdc++.h>
using namespace std;

int maxPerfectSubArray(vector<int> nums, int target)
{
    int high = 0, low = 0;
    int summer = nums[0];
    int minlen = INT_MAX;

    while (high < nums.size())
    {
        if (summer < target)
        {
            high++;
            summer += nums[high];
        }
        else
        {
            minlen = min(minlen, (high - low) + 1);
            summer -= nums[low];
            low++;
        }

        if (high == low && summer >= target)
            return 1;
    }

    if (minlen == INT_MAX)
        return 0;
    return minlen;
}
int main()
{
    vector<int> arr = {2, 3, 1, 2, 4, 3};
    cout << maxPerfectSubArray(arr, 7);
    return 0;
}
