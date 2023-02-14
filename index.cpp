#include <bits/stdc++.h>
using namespace std;

int main()
{
    int coins[] = {1, 12, 5, 10, 20, 50, 10, 200, 50, 24};

    sort(coins, coins + 5);
    for (int i = 0; i < 10; i++)
    {x  
        cout << coins[i] << " ";
    }

    return 0;
}
