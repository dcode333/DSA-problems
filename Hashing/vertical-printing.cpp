#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> hashmap;

void verticalPrinting(vector<int> arr, int head, int dist)
{
    if (head >= arr.size())
        return;

    hashmap[dist].push_back(arr[head]);

    verticalPrinting(arr, 2 * head + 1, dist - 1);
    verticalPrinting(arr, 2 * head + 2, dist + 1);
}

int main()
{
    vector<int> arr = {10, 7, 4, 3, 11, 14, 6};

    verticalPrinting(arr, 0, 0);

    for (auto it : hashmap)
    {
        for (int i = 0; i < it.second.size(); i++)
            cout << it.second[i] << " ";

        cout << endl;
    }

    return 0;
}
