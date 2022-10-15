// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

string xToEnd(string s)
{
    if (s.length() == 0)
        return "";

    char ch = s[0];
    string sub = xToEnd(s.substr(1));
    if (ch != 'x')
        return ch + sub;

    return sub + ch;
}

int main()
{

    cout << xToEnd("adxbfxcfxdi");

    return 0;
}