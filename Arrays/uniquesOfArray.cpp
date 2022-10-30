#include <bits/stdc++.h>
using namespace std;

// n + nlogn = nlogn

int main()
{
    vector<int> a = {1, 2, 1, 4, 2, 1, 2, 4, 6};
    sort(begin(a), end(a)); // nlogn

    for (int i = 0; i < a.size(); i++) // n
        if (a[i] != a[i + 1])
            cout << a[i] << " ";

    return 0;
}
