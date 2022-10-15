#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[3] = {1, 2, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
    int coutn = 0;

    for (int i = 0; i < len; i++)
    {
        coutn = 0;
        for (int j = i; j < len; j++)
        {
            coutn += arr[j];
            cout << coutn << endl;
        }
    }

    return 0;
}