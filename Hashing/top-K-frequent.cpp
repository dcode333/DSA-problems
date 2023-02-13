#include <bits/stdc++.h>
using namespace std;

void topKFreq(vector<int> arr, int k)
{
    unordered_map<int, int> hashmap;// freq computer
    priority_queue<pair<int, int>, vector<pair<int, int>>> minHp; // compute k most frequent elems
    vector<int> ans;

    for (int i = 0; i < arr.size(); i++)
        hashmap[arr[i]]++;

    for (auto i : hashmap)
        minHp.push(make_pair(i.second, i.first));

    for (int i = 0; i < k; i++)
    {
        ans.push_back(minHp.top().second);
        minHp.pop();
    }
}

int main()
{

    vector<int> arr = {2, 3, 3, 3, 4, 4, 5, 5};

    topKFreq(arr, 2);

    return 0;
}
