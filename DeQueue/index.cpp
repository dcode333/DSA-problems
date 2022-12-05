#include <bits/stdc++.h>
using namespace std;

//                      6 5 4 1 2 3
int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_front(4);
    cout<<dq.front();

    // for (auto i : dq)
    //     cout << i << " ";

    return 0;
}
