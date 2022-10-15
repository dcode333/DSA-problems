#include <bits/stdc++.h>
using namespace std;

int raiseToPowP(int num, int power)
{
    if (power == 0)
        return 1;
    return num * raiseToPowP(num, power - 1);
}

int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

int fibNthElem(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fibNthElem(n - 1) + fibNthElem(n - 2);
}

int printFibonacci(int a, int b, int limit)
{
    if (a >= limit)
        return a;
    cout << a << " ";
    int temp = a;
    a = b;
    b = temp + b;
    return printFibonacci(a, b, limit);
}

void dec(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    dec(n - 1);
}

void inc(int n)
{
    if (n == 0)
        return;
    inc(n - 1);
    cout << n << " ";

    // return; implicit return
}

int main()
{
    // inc(3);
    cout << "dadad";
    return 0;
}
