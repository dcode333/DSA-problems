#include <bits/stdc++.h>
using namespace std;

int main()
{
    string num = "32451";
    sort(num.begin(), num.end(), greater<int>());
    cout << num;
    return 0;
}