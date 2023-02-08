#include <bits/stdc++.h>
using namespace std;
/*
 => store 0th elem of k arrays with the arr and index
 => as top of the minheap is the smallest of all so pop and add to resultant
 => push the next elem if exists of the popped array to heap
*/

vector<int> mergeKsortedArrays(vector<vector<int>> arr)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minhp;
    vector<int> index;
    vector<int> res;

    for (int i = 0; i < arr.size(); i++)
    {
        index.push_back(0);
        minhp.push(make_pair(arr[i][0], i));
    }

    while (minhp.size() > 0)
    {
        int idx = minhp.top().second;
        index[idx]++;
        res.push_back(minhp.top().first);
        minhp.pop();

        if (index[idx] < arr[idx].size())
            minhp.push(make_pair(arr[idx][index[idx]], idx));
    }

    return res;
}

int main()
{

    vector<vector<int>> v = {{1, 2, 3},
                             {0, 5},
                             {6, 7, 8}};

    vector<int> res = mergeKsortedArrays(v);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}
