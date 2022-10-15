#include <bits/stdc++.h>
using namespace std;

//failed useCase : if array contains all -ve elems
int main()
{
    int arr[5] = {-2, -4, -2, -7, -4};
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
        cout << summer << endl;
    }

    cout << "Max Sum: " << MaxSum;
    return 0;
}