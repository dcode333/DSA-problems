#include <bits/stdc++.h>
using namespace std;
// (Algorithm)
// loop through given string
// store the ith char
// get permutaions for rest of the string

// tree on Register

void permutations(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        char single = s[i];
        string rest = s.substr(0, i) + s.substr(i + 1);

        permutations(rest, ans + single);
    }
}

int main()
{
    int n = 2;
    int a[n] = {1, 2};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            swap(a[j], a[j + 1]);
            for (int k = 0; k < n; k++)
                cout << a[k] << " ";
            cout << endl;
        }
    }

    return 0;
}
    