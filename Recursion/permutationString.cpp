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
    int a[6] = {10, 4, 4, 10, 4, 6};

    permutations("ABC", "");

    return 0;
}
