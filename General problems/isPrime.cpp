#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{

    int n = 100;
    bool flag = 0;

    for (int i = 2; i < sqrt(n); i++)
    {

        if (n % i == 0)
        {
            flag = 1;
            break; 
        }
    }

    flag == 0 ? cout << n << " is a prime no" : cout << n << " is not prime no";

    return 0;
}