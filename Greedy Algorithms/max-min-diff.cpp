#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> arr = {12, -3, 10, 0};

    sort(arr.begin(), arr.end());

    long long max = 0;
    long long min = 0;

    for (int i = 0; i < arr.size() / 2; i++)
    {
        max += arr[i + arr.size() / 2] - arr[i]; // subtracting n-n/2
        min += arr[2 * i + 1] - arr[2 * i];      // subtrracting odd from even indexes after sorting
    }

    cout << "Minimum is: " << min << endl;
    cout << "Maximum is: " << max << endl;

    return 0;
}