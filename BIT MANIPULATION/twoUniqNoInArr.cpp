
#include <bits/stdc++.h>
using namespace std;

//  ( Algorithm)
// 1  XOR all the array elems
// 2  from resultant we will obtain position of rightmost bit
// 3  XOR all the array elems having the right bit set on the position
// 4  1st uniq elem will be result of (3)
// 5  2nd uniq elem will be the XOR of (1) and (3)



int main()
{
    int a[6] = {10, 4, 4, 10, 4, 6};
    int XORsum = 0;
    int tempXOR;
    int newXOR = 0;
    int pos = 0;
    int setBit = 0;

    for (int i = 0; i < 6; i++)
    {
        XORsum = XORsum ^ a[i];
    }
    tempXOR = XORsum;
    while (setBit != 1)
    {
        setBit = XORsum & 1;
        pos++;
        XORsum = XORsum >> 1;
    }

    for (int i = 0; i < 6; i++)
    {
        if ((a[i] & (1 << pos - 1)) != 0)
            newXOR = newXOR ^ a[i];
    }

    cout << newXOR << " " << (tempXOR ^ newXOR); // 1000

    return 0;
}
