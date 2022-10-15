#include <iostream>
using namespace std;

int main()
{

    int n = 4;
    for (int i = 1; i <= 2 * n; ++i)
    {
        for (int j = 0; j < 2 * n; ++j)
        {
            if (i <= n)
                j >= (2 * n) - i || j <= i - 1 ? cout << "*" : cout << " ";
            else
                j <= ((2 * n) - i) || j >= i - 1 ? cout << "*" : cout << " ";
        }

        cout << " " << endl;
    }

    return 0;
}