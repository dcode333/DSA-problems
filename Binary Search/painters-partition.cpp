#include <bits/stdc++.h>
using namespace std;
// minimize the max
void paintersPartition(vector<int> boards, int low, int high, int painters)
{
    if (low > high)
    {
        cout << low;
        return;
    }

    int mid = (low + high) / 2;
    cout << "Mid: " << mid << endl;
    int sum = 0, painter = 1;

    for (int i = 0; i < boards.size(); i++)
    {

        if (sum + boards[i] > mid)
        {
            sum = 0;
            painter++;
        }
        if (painter > painters)
        {
            paintersPartition(boards, mid + 1, high, painters);
            return;
        }
        sum += boards[i];
    }
    paintersPartition(boards, low, mid - 1, painters);
}

int main()
{
    vector<int> arr = {10, 20, 30, 40};
    paintersPartition(arr, 10, 100, 2);
    return 0;
}

// void paintersPartition(vector<int> a, int low, int high, int painters)
//  {
//     if (low > high)
//     {
//         cout << low << endl;
//         return;
//     }
//     int middle = (low + high) / 2;
//     int sum = 0, painter = 1;

//     for (int i = 0; i < a.size(); i++)
//     {
//         if ((sum + a[i]) > middle)
//         {
//             if (painter < painters)
//             {
//                 painter++;
//                 sum = 0;
//                 i--;
//                 continue;
//             }
//             else
//             {
//                 paintersPartition(a, middle + 1, high, painters);
//                 return;
//             }
//         }
//         sum += a[i];
//     }
//     paintersPartition(a, low, middle - 1, painters);
// }