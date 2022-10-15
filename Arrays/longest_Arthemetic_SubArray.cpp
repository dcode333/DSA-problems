#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[7] = {10, 7, 4, 6, 8, 10, 11};
    int len = sizeof(arr) / sizeof(arr[0]);

    int differer = arr[1] - arr[0];
    int largestDiffSubArray = INT16_MIN;
    int diffCounter = 0;

    for (int i = 0; i < len - 1; i++)
    {
        if (differer == (arr[i + 1] - arr[i]))
            diffCounter++;
        else if (diffCounter > largestDiffSubArray)
        { 

            largestDiffSubArray = diffCounter;
            diffCounter = 1;
        }

        differer = arr[i + 1] - arr[i];
    }

    cout << "Length of longest subarray with same difference:  " << largestDiffSubArray + 1;
    return 0;
}