#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 5;
    int counter = 0;

    // Approach 2
    // Explainaion: when num is & with num-1 = num-1 resulting in a less 1 until it becomes 0
    // n & n-1 ==> n-1 and a less 1
    // eg: num = 3
    // 0011 and 0010 = 0010
    // 0010 and 0001 = 0000
    while (num)
    {
        num = num & (num - 1);
        counter++;
    }

    // Approach 1
    // for (int i = 0; i < 4; i++)
    // {
    //     if (getBit(num, i))
    //         counter++;
    // }

    cout << counter;
    return 0;
}
