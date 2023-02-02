#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(4);
    s.insert(2);

    // cout << *(s.lower_bound(3));
    for (auto i : s)
        cout << i << " ";

    return 0;
}
