#include <bits/stdc++.h>
using namespace std;

bool includes(int *arr, int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
            return true;
    }
    return false;
}

int main()
{
    int arr[10] = {10, 7, 4, 17, 1, 7, 4, 5, 1, 1};
    int len = sizeof(arr) / sizeof(arr[0]);

    // Approach #1

    // int dupliChecker[len] = {};
    // int smallest = INT_MAX;
    // int index = 0;
    // for (int i = len - 1; i >= 0; i--)
    // {
    //     if (includes(dupliChecker, len, arr[i]))
    //         smallest = min(i, smallest);
    //     else
    //     {
    //         dupliChecker[index] = arr[i];
    //         index++;
    //     }
    // }

    // Approach #2

    // int dupliChecker[100] = {-1};
    // for (int i = 0; i < 100; i++)
    // {
    //     dupliChecker[i] = -1;
    // }

    // int smallest = INT_MAX;
    // for (int i = 0; i < len; i++)
    // {
    //     if (dupliChecker[arr[i]] != -1)
    //         smallest = min(smallest, dupliChecker[arr[i]]);
    //     else
    //         dupliChecker[arr[i]] = i;
    // }

    cout << "Smallest i: " << smallest;

    return 0;
}