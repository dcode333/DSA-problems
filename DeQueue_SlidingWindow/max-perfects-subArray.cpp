#include <bits/stdc++.h>
using namespace std;
// if (2^n)-1 is prime then (2^n)-1 * (2^n-1) will give us a perfect number

bool isPerfect(int n)
{
    int sum = 0;

    for (int i = 1; i <= n / 2; i++)
        if (n % i == 0)
            sum = sum + i;

    if (sum == n)
        return true;

    return false;
}

int maxPerfectSubArray(vector<int> nums, int k)
{
    int perfectCount = 0;
    for (int i = 0; i < k; i++)
    {
        if (isPerfect(nums[i]))
            perfectCount++;
    }

    int low = 1, high = k;
    int maxPerfects = perfectCount;
    while (high < nums.size())
    {
        if (isPerfect(nums[low - 1]))
            perfectCount--;
        if (isPerfect(nums[high]))
            perfectCount++;

        maxPerfects = max(maxPerfects, perfectCount);

        low++;
        high++;
    }

    return maxPerfects;
}
int main()
{
    vector<int> arr = {1,2,3,4,5};
    cout << maxPerfectSubArray(arr, 4);
    return 0;
}
