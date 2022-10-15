#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

bool checkPythaTriplet(int a, int b, int c)
{
    int biggest = max(a, max(b, c));
    int n1, n2;
    if (biggest == a)
    {
        n1 = b;
        n2 = c;
    }
    else if (biggest == b)
    {
        n1 = a;
        n2 = c;
    }
    else
    {
        n1 = a;
        n2 = b;
    }

    if ((n1 * n1) + (n2 * n2) == (biggest * biggest))
        return true;
    return false;

    return false;
}

int main()
{
    int a, b, c;
    cout << "a :";
    cin >> a;
    cout << "b :";
    cin >> b;
    cout << "c :";
    cin >> c;

    checkPythaTriplet(a, b, c) ? cout << "Positive" : cout << "Negitive";

    return 0;
}