#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "ABCD";
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = str[i] + 32; // converting uppercase to lowercase
    }
    cout << str;

    return 0;
}