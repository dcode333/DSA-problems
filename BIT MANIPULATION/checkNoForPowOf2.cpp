#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Explaination
    //    suppose : 8 => 1000
    //     8-1 =    7 => 0111
    //    so
    //     1000 & 0100 == 0 (because there are no two 1's at the same pos)
    //                       if it is a pow of 2

    int checkNum = 4;
    if ((checkNum & checkNum - 1))
        cout << "Not pow of 2";
    else
        cout << "pow of 2";

    return 0;
}
