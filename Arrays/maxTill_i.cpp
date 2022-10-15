#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5] = {1, 4, 2, 3, -8};
    int len = sizeof(arr) / sizeof(arr[0]);
    int maxNum = arr[0];
    for (int i = 0; i < len; i++)
    {

        maxNum = max(maxNum, arr[i]);
        cout << maxNum << " ";
    }

    return 0;
}