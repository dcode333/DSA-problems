#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> coins, int amount)
{

    int minCoins = 0;
    int sum = 0;

    for (int i = coins.size() - 1; i >= 0; i--)
    {
        while (coins[i] + sum <= amount)
        {
            sum += coins[i];
            minCoins++;

            if (sum == amount)
                return minCoins;
        }
    }

    if (sum != amount)
        return -1;
    return minCoins;
}
int main()
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

    cout << coinChange(coins, 6249);

    return 0;
}
