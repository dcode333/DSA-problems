#include <bits/stdc++.h>
using namespace std;
#define n 100
class queue1
{
public:
    int *arr;
    int front;
    int back;

    queue1()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void enQueue(int data)
    {
        if (back == n - 1)
        {
            cout << "Buffer Full !\n";
            return;
        }
        back++;
        arr[back] = data;

        if (front == -1)
            front++;
    }

    void deQueue()
    {
        if (front == -1 || front > back)
        {
            cout << "Buffer Empty \n";
            return;
        }
        front++;
    }

    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "Buffer Empty \n";
            return -1;
        }
        return arr[front];
    }

    bool empty()
    {
        if (back == -1 || front > back)
            return true;

        return false;
    }
};

int main()
{
    queue1 q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    cout << q.peek() << endl;
    q.deQueue();
    cout << q.peek() << endl;
    q.deQueue();
    q.deQueue();

    cout << q.peek() << endl;

    return 0;
}
