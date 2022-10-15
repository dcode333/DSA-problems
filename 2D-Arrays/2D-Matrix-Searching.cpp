// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
// Matrix multiplications;
// Rows of 1st and cols of 2nd matrix should be same
int main()
{

    int n = 3;
    int a[n][n] = {{1, 2, 3},
                   {4, 7, 8},
                   {17, 18, 19}};
    int row = 0;
    int col = n - 1;
    int key = 19;

    //    00 01 02
    //    10 11 12
    //    20 21 22

    while (col >= 0 && row < n)
    {
        if (a[row][col] == key)
        {
            cout << "elem found at: " << row << col;
            return 0;
        }
        else if (a[row][col] > key)
            col--;
        else
            row++;
    }

    return 0;
}