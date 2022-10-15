#include <iostream>
using namespace std;

int main()
{

    int n = 5
    , s = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            cout << s << " ";
            s++;
        }

        cout << " " << endl;
    }

    return 0;
}