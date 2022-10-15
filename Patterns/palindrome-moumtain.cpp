#include <iostream>
#include <string.h>
using namespace std;

int main()
{

    int n = 5;
    string s = "1";
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n - i; j++)
            cout << " ";

        cout << s << endl;
        s = to_string(i + 1) + s + to_string(i + 1);
    }

    return 0;
}