#include <bits/stdc++.h>
using namespace std;

/* ALgo:
while( stack empty and top of stack >= a[i])
 pop

push(a[i])

*/

void prevSmaller(vector<int> a)
{
    stack<int> st;
    for (int i = 0; i < a.size(); i++)
    {
        while (!st.empty() && st.top() >= a[i])
            st.pop();
        if (st.empty())
            cout << a[i] << " : -1\n";
        else
            cout << a[i] << " : " << st.top() << endl;
        st.push(a[i]);
    }
}

void nextSmaller(vector<int> a)
{
    stack<int> st;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= a[i])
            st.pop();
        if (st.empty())
            cout << a[i] << " : -1\n";
        else
            cout << a[i] << " : " << st.top() << endl;
        st.push(a[i]);
    }
}

int main()
{
    vector<int> a = {4, 2, 1, 5, 6, 3, 2, 4, 2};
    prevSmaller(a);

    return 0;
}
