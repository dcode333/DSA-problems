#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
int main()
{
    int arr[] = {1, 2, 10, 7, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    int key = 12;
    int summer = 0;

    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (summer == key)
            {
                cout << "sum of elem from " << i + 1 << " to " << j << " = " << key;
                return 0;
            }
            summer += arr[j];
        }
        summer = 0;
    }

    return 0;
}