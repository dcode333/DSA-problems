#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    node *next;

    node(int n)
    {
        val = n;
        next = nullptr;
    }
};
class queuell
{
    node *front;
    node *back;

public:
    queuell()
    {
        front = nullptr;
        back = nullptr;
    }

    void enQueue(int n)
    {
        node *newNode = new node(n);
        if (front == nullptr)
        {
            back = newNode;
            front = newNode;
            return;
        }
        back->next = newNode;
        back = newNode;
    }

    void deQueue()
    {
        if (front == nullptr)
        {
            cout << "Buffer empty\n";
            return;
        }

        node *toDelete = front;
        front = front->next;
        delete toDelete;
    }

    int peek()
    {
        if (front == nullptr)
        {
            cout << "Buffer empty\n";
            return -1;
        }

        return front->val;
    }

    bool empty()
    {
        if (front == nullptr)
            return true;
        return false;
    }
};

int main()
{
    queuell q;
    q.enQueue(1);
    q.enQueue(22);
    cout << q.peek() << endl;
    q.deQueue();
    cout << q.peek() << endl;

    return 0;
}
