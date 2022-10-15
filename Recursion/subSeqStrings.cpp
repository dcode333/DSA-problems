#include <bits/stdc++.h>
using namespace std;

// call stack tree
// https://youtu.be/j9RG18jfnRY?t=1380

void subSeqStrings(string s, string ans)
{

    if (s.length() == 0)
    {
        cout << ans << endl;
        // if (ans.length() > 1)
        // {
        //     reverse(ans.begin(), ans.end());
        //     cout << ans << endl;
        // }
        return;
    }

    char ch = s[0];
    string sub = s.substr(1);

    subSeqStrings(sub, ans);
    subSeqStrings(sub, ans + ch);
}

int main()
{

    subSeqStrings("ABC", "");

    return 0;
}
