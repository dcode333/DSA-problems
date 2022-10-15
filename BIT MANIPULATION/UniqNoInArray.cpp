
#include <bits/stdc++.h>
using namespace std;

// Pending
int main()
{
    int a[5] = {3, 1, 3, 1, 10};
    // A^A=0
    // A^0=A
    // so xoring whole array will giv us the one uniq elem

    // XOR approach
    int XORsum = 0;

    for (int i = 0; i < 5; i++)
        XORsum = XORsum ^ a[i];

    cout << XORsum;

    // o(n) with Array Approach  (could be Increased Space Complexity)

    // int boolCheck[100];
    // for (int i = 0; i < 100; i++)
    //     boolCheck[i] = 0;

    // for (int i = 0; i < 5; i++)
    //     boolCheck[a[i]]++;

    // for (int i = 0; i < 100; i++)
    // {
    //     if (boolCheck[i] == 1)
    //     {
    //         cout << "\nUniq elem is: " << i;
    //         break;
    //     }
    // }

    return 0;
}
