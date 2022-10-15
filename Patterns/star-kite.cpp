#include <iostream>
#include <string.h>
using namespace std;

int main()
{

    int n = 7, m = 1, o = n - 1;
    for (int i = 1; i <= 2 * n; ++i)
    {
        int j;
        for (j = 1; j <= o; j++)
            cout << " ";

        for (j = 1; j <= m; j++)
            cout << "*";

        cout << endl;
        if (i >= n)
        {
            m -= 2;
            o++;
        }
        else
        {
            m += 2;
            o--;
        }
    }

    return 0;
}