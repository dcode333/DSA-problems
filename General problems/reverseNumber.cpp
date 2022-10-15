#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{

    int n = 12343;
    int count = (log10(n) + 1);
    
    for (int i = 0; i < count; i++)
    {
        cout << n % 10;
        n = n / 10;
    }

    return 0;
}