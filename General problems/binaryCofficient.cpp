#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int factorial(int num, int fact)
{
    if (num == 0)
        return fact;

    else
    {
        fact *= num;
        num--;
        return factorial(num, fact);
    }
}

int main()
{
    int n;
    int r;

    cout << "n :" << endl;
    cin >> n;

    cout << "r :" << endl;
    cin >> r;

    double nCr = factorial(n, 1) / (factorial(n - r, 1) * factorial(r, 1));
    cout << "Fact: " << nCr;

    return 0;
}