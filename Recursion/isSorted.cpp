
#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n)
{
    if (n == 0)
        return true;

    if (arr[n] >= arr[n - 1])
        return isSorted(arr, n - 1);
    else
        return false;
}

int main()
{
    int a[6] = {1, 2, 3, 4, 5, 6};

    cout << isSorted(a, 5);

    return 0;
}
