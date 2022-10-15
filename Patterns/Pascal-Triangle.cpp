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
    int n = 5;
    for (int i = 0; i < n; i++)
    {

        for (int k = 0; k < (n - i); k++)
            cout << " ";

        for (int j = 0; j <= i; j++)
            cout << factorial(i, 1) / (factorial(i - j, 1) * factorial(j, 1)) << " ";

        cout << endl;
    }

    return 0;
}