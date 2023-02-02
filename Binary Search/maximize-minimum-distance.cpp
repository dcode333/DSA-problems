#include <bits/stdc++.h>
using namespace std;

void maxMin(vector<int> a, int low, int high, int cows)
{
    if (low > high)
    {
        cout << high << endl;
        return;
    }

    int middle = (low + high) / 2;
    int cow = 1;
    int diff = a[0];
    for (int i = 0; i < a.size(); i++)
    {
        if ((a[i] - diff) >= middle)
        {
            if (cow < cows)
            {
                cow++;
                diff = a[i];
            }
            else
            {
                maxMin(a, middle + 1, high, cows);
                return;
            }
        }
    }
    maxMin(a, low, middle - 1, cows);
}

int main()
{
    vector<int> arr = {1, 2, 4};
    maxMin(arr, 1, 8, 2);
    return 0;
}
