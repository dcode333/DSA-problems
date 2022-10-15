#include <iostream>
#include <string.h>
using namespace std;

int main()
{

    int n = 9;
    string s = "1";
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 1; j <= n; j++)
        {
            (i + j) % 4 == 0 ? cout << "*" : cout << " ";
            (i % 2) == 0 && (i + j) % 4 != 0 && (i + j) % 2 == 0 ? cout << '*' : cout << " ";
        }

        cout << "\n";
    }

    return 0;
}