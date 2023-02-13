#include <bits/stdc++.h>
using namespace std;
/*
 See if the sum upto ith repeats and if it repeats than
 the subArrray from its previous index till the ith index
 will be the subArray with sum=0
*/

int largestSubArraySum(vector<int> arr)
{
    unordered_map<int, int> hashmap;
    int maxLen = INT_MIN;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            maxLen = i + 1;
            continue;
        }
        if (hashmap.find(sum) == hashmap.end())
            hashmap[sum] = i;
        else
            maxLen = max(maxLen, i - hashmap[sum]);
    }

    if (maxLen != INT_MIN)
        return maxLen;
    return 0;
}

int smallestSubArraySum(vector<int> arr)
{
    unordered_map<int, int> hashmap;
    hashmap[0] = -1;
    int minLen = INT_MAX;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        if (arr[i] == 0)
            return 1;

        if (hashmap.find(sum) == hashmap.end())
            hashmap[sum] = i;
        else
        {
            minLen = min(minLen, i - hashmap[sum]);
            hashmap[sum] = i;
        }
    }

    if (minLen != INT_MAX)
        return minLen;
    return 0;
}

int main()
{

    vector<int> arr = {4, 4, -8, 1, 1, 9, 7, 20, -38};

    cout << smallestSubArraySum(arr);
    cout << endl
         << largestSubArraySum(arr);

    return 0;
}
