#include <bits/stdc++.h>
using namespace std;
// Explain: https://youtu.be/wOtRnD0f7Yw?t=290

int pairProb(int n)
{
    if (n == 0 || n == 1 || n == 2)
        return n;

    return pairProb(n - 1) + pairProb(n - 2) * (n - 1);
}

int main()
{

    cout << pairProb(3);
    return 0;
}
