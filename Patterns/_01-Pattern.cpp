#include <iostream>
#include <string.h>
using namespace std;

int main()
{

    int n = 10;
    string s = "1";
    for (int i = 1; i <= n; ++i)
    {
        cout << s << "\n";
        (i % 2) == 0 ? s = "1 " + s : s = "0 " + s;
    }

    return 0;
}