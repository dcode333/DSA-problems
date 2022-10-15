#include <bits/stdc++.h>
using namespace std;

// O(n) solution => constraint : Array should be sorted
// without constraint solution is by (checkBool array)

int main()
{
    int arr[7] = {-3, -1, 0, 1, 2, 3, 10};

    int len = sizeof(arr) / sizeof(arr[0]);
    int smallest = INT_MAX;
    bool isZero = false;

    for (int i = 0; i < len; i++)
    {
        if (arr[i] >= 0)
        {
            smallest = min(arr[i], smallest);
            if (arr[i] == smallest + 1)
                smallest = arr[i];
            if (arr[i] == 0)
                isZero = true;
        }
    }

    isZero ? cout << "Smallest is: " << smallest + 1 : cout << "Smallest is : 0";

    return 0;
}
