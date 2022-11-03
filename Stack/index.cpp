#include <bits/stdc++.h>
using namespace std;
#define n 100

class Stack
{
    int *arr;
    int top;

public:
    Stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int data)
    {
        if (top == n - 1)
        {
            cout << "Stack overflowed\n";
            return;
        }
        top++;
        arr[top] = data;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Empty\n";
            return;
        }
        top--;
    }
    int Top()
    {
        if (top == -1)
        {
            cout << "Stack Empty\n";
            return -1;
        }
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};


int main()
{
    // Stack s;
    // s.push(1);
    // s.push(2);
    // s.push(3);

    // cout << s.Top() << "\n";
    // cout << s.empty();

    //{[}]{}() iv
    //{}[]{}()  v
    //[{}]{}()  v
    //{[]}{}()  v

    //  }] } )
    //{[  { (
    //

    // cout << balancedParantheses("{([])}");
    return 0;
}
