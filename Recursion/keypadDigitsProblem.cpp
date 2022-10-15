
#include <bits/stdc++.h>
using namespace std;
string a[10] = {"", "./", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keypad(string s, string t)
{
    if (s.length() == 0)
        return;

    char ch = s[0];
    string sub = s.substr(1);
    keypad(sub, t);
    for (int i = 0; i < t.length(); i++)
        cout << ch << t[i] << endl;
}

int main()
{

    keypad(a[2], a[9]);

    return 0;
}
