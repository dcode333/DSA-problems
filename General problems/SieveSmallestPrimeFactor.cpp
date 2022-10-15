#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 50;
    int a[n + 1] = {0};

    int i = 2;
    while ((i * i) <= n)
    {
        for (int j = (i * i); j < n; j += i)
            if (a[j] == 0)
                a[j] = i;

        i++;
    }

    for (int i = 2; i < n; i++)
        cout << a[i] << " => spf: " << i << endl;

    return 0;
}
