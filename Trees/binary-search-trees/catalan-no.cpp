#include <bits/stdc++.h>
using namespace std;
/*
Catalan: summation(Ci*C(n-i))
*/

int catalan(int n)
{
    if (n <= 1)
        return 1;

    int sum = 0;
    for (int i = 0; i < n ; i++)
        sum += catalan(i) * catalan(n - i - 1);

    return sum;
}

int main()
{

    cout<<catalan(9);

    return 0;
}
