#include <bits/stdc++.h>
using namespace std;
//pending
int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = sizeof(arr) / sizeof(arr[0]); // returns rows
    int col = sizeof(arr[0]) / sizeof(int);  // returns col

    //    0(n) approach
    // for (int i = 0; i < rows; i++)
    // {
    for (int j = 0; j < col * 3; j += 3)
        cout << arr[1][j] << " ";
    cout << endl;
    // }
    return 0;
}