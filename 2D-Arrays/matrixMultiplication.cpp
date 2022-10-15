// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
// Matrix multiplications;
// Rows of 1st and cols of 2nd matrix should be same
int main()
{

    int n = 3;
    int a[n][n] = {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9}};

    int a1[n][n] = {{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}};
    int a2[n][n] = {};

    int multi = 0;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                multi += a[k][j] * a[j][i];

            cout << multi << " ";
        }
        cout << endl;
        multi = 0;
    }

    return 0;
}