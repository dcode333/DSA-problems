#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{

    int n = 153, armStrong = 0, m = n;
    while (n > 0)
    {
        int current = n % 10;
        armStrong += round(pow(current, 3));
        n = n / 10;
    }

    armStrong == m ? cout << "is Armstrong" : cout << "not Armstrong";

    return 0;
}