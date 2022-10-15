#include <bits/stdc++.h>
using namespace std;

string binAdd(string a, string b)
{

    int carry = 0;
    string ans = " ";
    for (int i = a.length(); i >= 0; i--)
    {
        if (a[i] == '0' && b[i] == '1')
        {
            if (carry)
            {
                ans += '0';
                carry = 1;
            }
            else
            {
                ans += '1';
                carry = 0;
            }
        }
        if (a[i] == '0' && b[i] == '0')
        {

            if (carry)
                ans += '1';

            else
                ans += '0';

            carry = 0;
        }
        if (a[i] == '1' && b[i] == '1')
        {
            if (carry)
                ans += '1';

            else
                ans += '0';

            carry = 1;
        }

        
    }
    return ans + to_string(carry);
}

int main()
{
    cout << binAdd("101", "101");

    return 0;
}