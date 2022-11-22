#include <bits/stdc++.h>
using namespace std;

class stackingQueue
{
    stack<int> s1;
    stack<int> s2;
    int peek = -1;

public:
    void deQueueRec()
    {
        if (s1.empty())
        {
            cout << "Buffer Empty\n";
            peek = -1;
            return;
        }
        if (s1.size() == 1)
        {
            s1.pop();
            return;
        }

        if (s1.size() == 2)
            peek = s1.top();

        int n = s1.top();
        s1.pop();
        deQueueRec();

        s1.push(n);
    }

    void enqueue(int n)
    {
        if (s1.empty())
            peek = n;

        s1.push(n);
    }

    void dequeue()
    {
        if (s1.empty())
        {
            cout << "Buffer empty\n";
            peek = -1;
            return;
        }

        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s2.pop();
        if (!s2.empty())
            peek = s2.top();
        else
            peek = -1;

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int getPeek()
    {
        return peek;
    }
};

int main()
{
    stackingQueue sq;
    sq.enqueue(2);
    sq.enqueue(3);
    sq.enqueue(4);
    sq.enqueue(5);
    sq.deQueueRec();
    cout << sq.getPeek() << endl;
    return 0;
}
