#include <bits/stdc++.h>
using namespace std;

void insertBottom(stack<int> &s, int e)
{
    if (s.empty())
    {
        s.push(e);
        return;
    }

    int T = s.top();
    s.pop();
    insertBottom(s, e);

    s.push(T);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
        return;

    int T = s.top(); // 5 4 3 2 1
    s.pop();
    reverseStack(s);
    insertBottom(s, T);
}

int main()
{
    stack<int> s;
    s.push(13);
    s.push(14);
    s.push(15);
    s.push(16);
    reverseStack(s);
    //(5-(6/3))  =>

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
