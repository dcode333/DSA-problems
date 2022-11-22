#include <bits/stdc++.h>
using namespace std;

// [1] [2] [3] [4] [5]
// [1] [2] [3] [4] []

class queueingStack
{
    queue<int> q1;
    queue<int> q2;

public:
    void push(int n)
    {
        q1.push(n);
    }

    void pop()
    {
        if (q1.empty())
        {
            cout << "Buffer Empty !!";
            return;
        }

        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int top()
    {
        return q1.back();
    }
};

int main()
{
    queueingStack qs;
    qs.push(1);
    qs.push(2);
    qs.push(3);
    qs.pop();
    qs.pop();

    cout << qs.top();

    return 0;
}
