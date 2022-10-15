#include <bits/stdc++.h>
using namespace std;

int getBit(int num, int position)
{
    return (num & (1 << position)) != 0; // Here it will tell either 1 or 0 at pos of num
}
//  z
int setBit(int num, int position)
{
    int mask = (1 << position);
    return (num | mask); // Here it will set 1 at pos of num
}

int clearBit(int num, int position)
{
    int mask = (~(1 << position));
    return (num & mask); // Here it will set 0 at pos of num (~ = 1's complement)
    // clearBit(5, 0)
    // 0101
    // 0001   (1 << 0)
    // 1110   (~(1 << position))
    // 0101 & 1110 (num & (~(1 << position)))
    // => 0100 => 4
}

int updateBit(int num, int pos, int updateTo)
{
    // if (updateTo)
    //     return setBit(num, pos);
    // return clearBit(num, pos);

    int mask = (~(1 << pos));
    num = (num & mask);
    return num | updateTo << pos;
}

int main()
{
    cout << clearBit(2, 0); // 0101
    return 0;
}
