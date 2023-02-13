#include <bits/stdc++.h>
using namespace std;
/*
unordered_map:
                 Avg/Best  |  worst (IN CASE OF COLLISION)
  *  insertion :   O(1)        O(N)
  *  accessing :   O(1)        O(N)

  *  Key is always a single data type
  *  key/val pair is in unsorted order

map:

  *  insertion :   O(LOG N)
  *  accessing :   O(LOG N)

  *  Key can be any data type
  *  key/val pair is in sorted order
*/

int maxOcccurringLen(vector<int> arr, int num)
{
    unordered_map<int, int> hashmap;

    for (int i = 0; i < arr.size(); i++)
        hashmap[arr[i]] += 1;

    return hashmap[num];
}

int main()
{
    vector<int> arr = {2, 3, 4, 2, 3, 6, 2, 6, 9};

    // cout << maxOcccurringLen(arr, 2);

    map<int, int> hashmap;

    for (int i = 0; i < arr.size(); i++)
        hashmap[arr[i]]++;

    for (auto i : hashmap)
        cout << i.first << " " << i.second << endl;

    return 0;
}
