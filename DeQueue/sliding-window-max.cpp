#include <bits/stdc++.h>
using namespace std;

/* Algorithm: [not sliding really]
 traverse k times to deque the useful elems (pop_Back until empty or current>back)
-> push i
-> push front to ans
traverse k to len
-> check if front is in window (pop_front if not)
-> keep on storing useful elems

*/

// ((a+b))
void maxSlideWindow(vector<int> v, int k)
{
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && v[i] > v[dq.back()]) // until ith elem is greater than backth elem of dq we keep poping
            dq.pop_back();

        dq.push_back(i);
    }

    ans.push_back(v[dq.front()]);

    for (int i = k; i < v.size(); i++)
    {
        if (dq.front() == i - k) // if front of dq(max elem) is in window than ok vv pop
            dq.pop_front();

        while (!dq.empty() && v[i] > v[dq.back()]) // until ith elem is greater than backth elem of dq we keep poping
            dq.pop_back();

        dq.push_back(i);
        ans.push_back(v[dq.front()]);
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}

int main()
{
    vector<int> v = {4, 1, 3, 5, 1, 2};
    maxSlideWindow(v, 3);
    return 0;
}
