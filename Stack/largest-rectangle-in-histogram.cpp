#include <bits/stdc++.h>
using namespace std;

/*Algorithm:
1) compute a vector for nearest Prev smaller digit Index for all elems (not found = -1)
2) compute a vector for nearest next smaller digit Index for all elems (not found = arraySize)
4) traverse through array => (next-prev-1)*arr[i] will give the area of a[i]
5) (next-prev-1)*arr[i]:
                i.e.  - for some elem 2 at index 6
                      - assume there is no elem smaller next and prev to it then
                      - 9=arrSize, 2=a[i]
                      - 9-(-1)-1 = 9*2 = 18

*/

vector<int> prevSmaller(vector<int> a)
{
    stack<int> st;
    vector<int> smallerIndexs;
    for (int i = 0; i < a.size(); i++)
    {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (st.empty())
            smallerIndexs.push_back(-1);
        else
            smallerIndexs.push_back(st.top());
        st.push(i);
    }

    return smallerIndexs;
}

vector<int> nextSmaller(vector<int> a)
{
    stack<int> st;
    vector<int> smallerIndexs;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (st.empty())
            smallerIndexs.push_back(a.size());
        else
            smallerIndexs.push_back(st.top());
        st.push(i);
    }

    return smallerIndexs;
}

int largestRec(vector<int> a)
{
    int ans = INT_MIN;
    vector<int> smInx = prevSmaller(a);
    vector<int> nxInx = nextSmaller(a);
    int nxInxSize = nxInx.size() - 1;
    for (int i = 0; i < a.size(); i++)
        ans = max(ans, (nxInx[nxInxSize - i] - smInx[i] - 1) * a[i]);

    return ans;
}

int main()
{
    vector<int> a = {4, 2, 1, 5, 6, 3, 2, 4, 2};
    // optimized
    cout << largestRec(a);

    // Brute Force
    // int minh = INT_MAX;
    // int ans = INT_MIN;
    // for (int i = 0; i < a.size(); i++)
    // {
    //     minh = INT_MAX;
    //     for (int j = i; j < a.size(); j++)
    //     {
    //         minh = min(minh, a[j]);
    //         cout << minh << endl;
    //         int len = j - i + 1;
    //         ans = max(ans, len * minh);
    //     }
    //     cout <<"Ans: "<<ans<< endl;
    // }

    return 0;
}
