#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    int a[n + 1] = {};

    for (int i = 0; i < n; i++)
        a[i] = i;

    int i = 2;
    while ((i * i) <= n)
    {
        for (int j = (i * i); j < n; j += i)
            a[j] = 0;

        i++;
    }

    for (int i = 2; i < n; i++)
        if (a[i])
            cout << a[i] << "  ";

    return 0;
}
