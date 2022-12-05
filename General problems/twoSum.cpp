#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<int> a = {1, 2, 4, 5, 3, 2, 4, 5};
    sort(a.begin(), a.end());
    int low = 0;
    int hi = a.size() - 1;
    int target = 9;

    for (int i = 0; i < a.size(); i++)
    {

        while (low < hi)
        {
            if (low == i)
            {
                low++;
                continue;
            }

            if (hi == i)
            {
                hi--;
                continue;
            }

            if ((a[i] + a[low] + a[hi]) < target)
                low++;
            else if ((a[i] + a[low] + a[hi]) > target)
                hi--;
            else
            {
                cout << i << " " << low << " " << hi << " ";
                return 0;
            }
        }
    }

    return 0;
}